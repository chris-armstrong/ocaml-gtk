open Parse_gobject_model
open Gobject_model
open Pretty_print
open Escape
open Entity

(* Format.printf "structure %a\n" Gobject_model.pp_repositoryType rep *)

let print_ml_start ml =
  ml "[@@@alert \"-unsafe\"]";
  ml "";
  ml "open Gobject0"

let print_c_start cf =
  cf "#define G_SETTINGS_ENABLED_BACKEND\n";
  cf "#define G_SETTINGS_ENABLE_BACKEND";
  cf "#include <gio/gsettingsbackend.h>";
  cf "#include <gio/gunixconnection.h>";
  cf "#include <gio/gunixcredentialsmessage.h>";
  cf "#include <gio/gunixfdlist.h>";
  cf "#include <gio/gunixfdmessage.h>";
  cf "#include <gio/gunixinputstream.h>";
  cf "#include <gio/gunixmounts.h>";
  cf "#include <gio/gunixoutputstream.h>";
  cf "#include <gio/gunixsocketaddress.h>";
  cf "#include <gtk/gtk.h>";
  cf "#include <gtk/gtkunixprint.h>";
  cf "#define CAML_NAME_SPACE";
  cf "#include <caml/mlvalues.h>";
  cf "#include <caml/memory.h>";
  cf "#include <caml/callback.h>";
  cf "#include <caml/alloc.h>";
  cf "#include <caml/fail.h>";
  cf "#include \"ml_gobject0.h\""

let rec find_ancestors
    (all_classes_by_entity_name : (entityDescriptor * 'a) EntityMap.t)
    ?(ancestors = Ok []) ((entity_ns, entity_name), (_, class_type)) =
  CCOption.map_or ~default:ancestors
    (fun parent_joined_name ->
      let parent_entity_name = map_entity_name entity_ns parent_joined_name in
      let parent_opt =
        EntityMap.get parent_entity_name all_classes_by_entity_name
      in
      CCResult.(
        let* parent =
          CCOption.to_result
            (Format.sprintf "Could not find parent entity %s for %s.%s"
               parent_joined_name entity_ns entity_name)
            parent_opt
        in
        let* ancestors = ancestors in
        let new_ancestors = (parent_entity_name, parent) :: ancestors in
        find_ancestors all_classes_by_entity_name ~ancestors:(Ok new_ancestors)
          (parent_entity_name, parent)))
    class_type.parent

let print_class_ancestors ml all_classes all_classes_by_entity_name =
  all_classes
  |> List.map (fun entity ->
         let ancestors = find_ancestors all_classes_by_entity_name entity in
         (entity, ancestors))
  |> List.iter (fun ((class_entity_name, (er, _)), ancestor_res) ->
         match ancestor_res with
         | Ok ancestors ->
             let ancestor_entities =
               List.map (fun (_, (er, _)) -> er) ancestors
             in
             let entity_chain = er :: (List.rev ancestor_entities) in
             ml
               (Format.asprintf "type %s = [%a] obj" (ml_name er)
                  (Format.pp_print_list ~pp_sep:pp_pipe Format.pp_print_string)
                  (entity_chain
                  |> List.map c_type_name
                  |> List.map (fun x -> "`" ^ x)))
         | Error e ->
             Format.eprintf "Error finding ancestors for %a: %s" pp_string_pair
               class_entity_name e)

let get_classes_from_namespace namespace =
  (match namespace with Namespace ({ name; _ }, entities) -> (name, entities))
  |> fun (namespace, entities) ->
  CCList.filter_map
    (function
      | er, Class cr -> Some ((namespace, er.name), (er, cr)) | _ -> None)
    entities

let process_namespaces namespaces =
  let all_classes_by_entity_name =
    namespaces
    |> CCList.flat_map get_classes_from_namespace
    |> Entity.EntityMap.of_list
  in
  namespaces
  |> List.iter (fun namespace ->
         match namespace with
         | Namespace (({ name; _ } as ns), entities) ->
             let ml_file = Out_channel.open_text (name ^ ".ml") in
             let ml = Printf.fprintf ml_file "%s\n" in
             let c_file = Out_channel.open_text ("ml_" ^ name ^ ".c") in
             let cf = Printf.fprintf c_file "%s\n" in
             print_ml_start ml;
             print_c_start cf;
             let all_classes =
               get_classes_from_namespace (Namespace (ns, entities))
             in
             print_class_ancestors ml all_classes all_classes_by_entity_name;
             (* print_class_ancestors ml name entities all_entities_by_namespace; *)
             Out_channel.close ml_file;
             Out_channel.close c_file)

(* entity name as namespace * name *)
let get_namespaces_from_repositories repositories =
  repositories
  |> CCList.filter_map (function Repository (namespaces, _) -> Some namespaces)
  |> CCList.flatten

let parse filenames =
  filenames
  |> List.map (fun filename ->
         let source =
           Xml_helpers.open_file_source ~ns:namespace_gobject filename
         in
         try read source
         with Failure x ->
           Printf.eprintf "Error reading %s: %s" filename x;
           raise (Failure x))

let generate () =
  let files = List.tl (Sys.argv |> Array.to_list) in
  Format.printf "Processing GObject entries: %a"
    (Format.pp_print_list ~pp_sep:pp_comma Format.pp_print_string)
    files;
  let repositories = parse files in
  let all_namespaces = get_namespaces_from_repositories repositories in
  process_namespaces all_namespaces;
  ()

(* let namespaces = all_namespaces_from_repositories repositories in
   process_namespaces namespaces *)

let _ = generate ()