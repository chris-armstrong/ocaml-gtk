open Parse_gobject_model
open Gobject_model

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

let rec find_ancestors ?(ancestors = []) namespace parent all_entities_by_namespace =
  match parent with
  (* final parent *)
  (* | "GObject.Object" -> Ok (List.rev ((namespace, parent) :: ancestors)) *)
  | _ -> (
      let split_parent = String.split_on_char '.' parent in
      let (namespace, parent) = (
        match split_parent with
        | [single_parent] -> (namespace, single_parent)
        | [new_namespace; new_parent] -> (new_namespace, new_parent)
        | _ -> raise (Failure (Printf.sprintf "Cannot process namespaced class \"%s\"" parent))
      ) in
      let namespace_classes = List.assoc namespace all_entities_by_namespace in
      match List.assoc_opt parent namespace_classes with
      (* follow to parent *)
      | Some (Some new_parent) ->
          find_ancestors ~ancestors:((namespace, parent) :: ancestors) namespace new_parent
            all_entities_by_namespace
      (* empty parent *)
      | Some None -> Ok (List.rev ((namespace, parent) :: ancestors))
      | None -> Error ("Could not find parent of " ^ namespace ^ "." ^ parent))

type class_with_parent = string * string option [@@deriving show]

(* Return all the class entities as a string pair in the form (class_name, parent_name) *)
let classes_with_parent_from_entities entities =
  entities
  |> List.filter_map (function
       | Class (name, { parent; _ }) -> Some (name, parent)
       | _ -> None)

let pp_comma = (fun ppf () -> Format.fprintf ppf ", @ ")
let pp_arrow = (fun ppf () -> Format.fprintf ppf " -> ")
let pp_string_pair = (fun ppf (x, y) -> Format.fprintf ppf "%s.%s" x y)

let print_class_ancestors _ namespace entities all_entities_by_namespace =
  let namespace_classes = classes_with_parent_from_entities entities in
  let all_classes_with_parent_by_namespace = List.map (
    fun (namespace, entities) -> (namespace, classes_with_parent_from_entities entities)
  ) all_entities_by_namespace in
  (* Format.printf "classes with parents: %a\n\n"
    (Format.pp_print_list ~pp_sep:pp_comma pp_class_with_parent)
    namespace_classes; *)
  List.iter
    (fun (name, parent) ->
      let ancestors =
        match parent with
        | Some parent -> find_ancestors namespace parent all_classes_with_parent_by_namespace
        | None -> Ok []
      in
      match ancestors with
      | Ok [] ->
          Format.printf "%s :-> <root>\n" name
      | Ok ancestors ->
          Format.printf "%s :-> %a\n" name
            (Format.pp_print_list ~pp_sep:pp_arrow pp_string_pair)
            ancestors
      | Error error -> Format.printf "%s failed ancestor test: %s\n" name error)
    namespace_classes

let process_namespace namespace all_entities_by_namespace =
  match namespace with
  | Namespace ({ name; _ }, entities) ->
      (* let ml_file = Out_channel.open_text (namespace.name ^ ".ml") in
      let ml = Printf.fprintf ml_file in
      let c_file = Out_channel.open_text (namespace.name ^ ".c") in
      let cf = Printf.fprintf c_file in
      print_ml_start (fun m -> ml "%s\n" m);
      print_c_start (fun c -> cf "%s\n" c); *)
      print_class_ancestors (fun _ -> ()) name entities all_entities_by_namespace
      (* Out_channel.close ml_file;
      Out_channel.close c_file *)

let parse filenames =
  filenames
  |> List.map (fun filename ->
         let source =
           Xml_helpers.open_file_source ~ns:namespace_gobject filename
         in
         try read source with
          | Failure x -> (Printf.eprintf "Error reading %s: %s" filename x; raise (Failure x)))

let generate () =
  let repositories =
    parse
      [
        "GObject-2.0.xml";
        "GLib-2.0.xml";
        "Gio-2.0.xml";
        "Gdk-4.0.xml";
        "Gtk-4.0.xml";
      ]
  in
  let namespaces =
    repositories
    |> List.map (fun rep ->
           match rep with Repository (namespaces, _) -> namespaces)
    |> List.flatten
  in
  let all_entities_by_namespace =
    namespaces
    |> List.map (function Namespace ({ name; _ }, entities) -> (name, entities))
  in
  List.iter
    (fun namespace -> process_namespace namespace all_entities_by_namespace)
    namespaces

let _ = generate ()