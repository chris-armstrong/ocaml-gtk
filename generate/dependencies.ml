open Util
module StringSet = CCSet.Make (String)

(**
  Sorted dependency - either standalone or mutually dependent (recursive)
  *)
type 'a sorted = Standalone of 'a | Recursive of 'a list

module Tuple = struct
  let t2_first (x, _) = x
  let t2_second (_, x) = x
  let map_t2_first t2_list = List.map t2_first t2_list
  let map_t2_second t2_list = List.map t2_second t2_list
end

let pp_print_string_list = Format.(pp_print_list ~pp_sep:pp_print_space pp_print_string)

let rec find_knot ?(chain = []) name entities_with_deps =
  match CCList.drop_while (fun x -> x <> name) chain with
  | [] ->
      let deps =
        entities_with_deps
        |> List.find_map (fun (((_, entity_name), _), entity_deps) ->
               if entity_name = name then Some entity_deps else None)
        |> Option.get
        |> StringSet.remove name
        |> StringSet.to_list
      in
      Format.printf "Deps of %s: %a\n" name pp_print_string_list deps;
      deps
      |> List.find_map (fun dep ->
             find_knot ~chain:(List.rev (name :: chain)) dep entities_with_deps)
  | sub_chain -> Some sub_chain

let rec sort_by_dependencies ?(sorted_classes = []) find_dependencies = function
  | [] -> sorted_classes
  | remaining_classes -> (
      (* calculate the set of dependencies for each class *)
      let remaining_class_names =
        entity_pair_list_to_names_list remaining_classes
      in
      let remaining_with_dependencies =
        List.map
          (fun cl ->
            let remaining_dependencies =
              remaining_class_names |> CCList.inter ~eq:String.equal (find_dependencies cl)
                |> StringSet.of_list
            in
            (cl, remaining_dependencies))
          remaining_classes
      in
      (* sort into those that not depending on those in remaining_classes, and those that are *)
      let free, stuck =
        List.partition
          (fun (((_, name), _), dependencies) ->
            if StringSet.equal dependencies StringSet.empty then true
            else if StringSet.equal dependencies (StringSet.add name StringSet.empty) then
              true
            else false
          )
          remaining_with_dependencies
      in

      let free_classes = List.map (fun (x, _) -> Standalone x) free in
      if List.length free > 0 then
        (* we have free classes, no need to look for knots *)
        let stuck_classes = Tuple.map_t2_first stuck in
        sort_by_dependencies
          ~sorted_classes:(List.concat [ sorted_classes; free_classes ])
          find_dependencies stuck_classes
      else
        (* find a mutually recursive cluster and eliminate it *)
        let knot =
          stuck
          |> List.find_map (fun (((_, name), _), _) -> find_knot name stuck)
        in
        Format.(
          printf "Looking for chain in %a\n"
            (pp_print_list ~pp_sep:pp_print_space pp_print_string)
            (List.map (fun (((_, name), _), _) -> name) stuck));

        match knot with
        | Some chain ->
            Format.(printf "Found chain: %a\n\n" (pp_print_list ~pp_sep:pp_print_space pp_print_string) chain);
            let knotted_classes, unknown_classes =
              List.partition_map
                (fun ((((_, entity_name), _) as entity), _) ->
                  if List.exists (( = ) entity_name) chain then Left entity
                  else Right entity)
                stuck
            in
            let knot_recursion = [ Recursive knotted_classes ] in
            sort_by_dependencies
              ~sorted_classes:
                (List.concat [ sorted_classes; free_classes; knot_recursion ])
              find_dependencies unknown_classes
        | None -> raise (Failure "Unresolvable recursion"))
