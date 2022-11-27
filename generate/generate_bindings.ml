open Parse_gobject_model
open Gobject_model
open Pretty_print
open Escape
open Entity

(* module type EntityEnvironment = sig
     val ml_name : string -> string
     val ml_name0 : string -> string
   end

   module type EntityEnvironmentFactory = sig
     val for_namespace : string -> (module EntityEnvironment)
   end

   let make_env_factory namespaces =
     let entities = Entity.make_all_entities namespaces
     in
     (module struct
       let for_namespace namespace =
         (module struct
           let ml_name0 name =
             let entity_ns, entity_name = map_entity_name namespace name in
             if entity_ns = namespace then ml_name0 entity_name
             else entity_ns ^ "." ^ ml_name0 entity_name

           let ml_name name =
             let entity_ns, entity_name = map_entity_name namespace name in
             if entity_ns = namespace then ml_name entity_name
             else entity_ns ^ "." ^ ml_name entity_name
         end : EntityEnvironment)
     end : EntityEnvironmentFactory) *)

(* Format.printf "structure %a\n" Gobject_model.pp_repositoryType rep *)

type environment = {
  namespace : string;
  all_entities : (entityDescriptor * entityType) EntityMap.t;
}

let print_ml_start ml =
  ml "[@@@alert \"-unsafe\"]";
  ml "";
  ml "open! Gobject0"

let sprintf = Format.asprintf

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
             let entity_chain = er :: List.rev ancestor_entities in
             ml
               (Format.asprintf "type %s = [%a] obj" (ml_name er.name)
                  (Format.pp_print_list ~pp_sep:pp_pipe Format.pp_print_string)
                  (entity_chain |> List.map c_type_name
                  |> List.map (fun x -> "`" ^ x)))
         | Error e ->
             Format.eprintf "Error finding ancestors for %a: %s\n"
               pp_string_pair class_entity_name e)

let print_bitfields ml all_bitfields =
  List.iter
    (fun ((_, _), (er, (br : bitfieldRecord))) ->
      ml "";
      ml (Printf.sprintf "module %s = struct" er.name);
      List.iter
        (fun (member : memberRecord) ->
          ml
            (Printf.sprintf "  let %s = %s"
               (escape_ml_keyword member.name)
               member.value))
        br.members;
      ml "end")
    all_bitfields

let print_enumerations ml all_enumerations =
  all_enumerations
  |> List.iter (fun (_, (er, (en : enumerationRecord))) ->
         ml "";
         ml (Printf.sprintf "type %s = " (ml_name0 er.name));
         List.iter
           (fun (member : memberRecord) ->
             ml (sprintf "  | %s" (cs_name member.name)))
           en.members)

let get_x_from_namespace namespace matcher =
  match namespace with
  | Namespace ({ name; _ }, entities) ->
      CCList.filter_map
        (fun (er, et) ->
          et |> matcher
          |> CCOption.map (fun matched_et ->
                 ((name, er.name), (er, matched_et))))
        entities

let get_classes_from_namespace namespace =
  get_x_from_namespace namespace (function Class ct -> Some ct | _ -> None)

let get_bitfields_from_namespace namespace =
  get_x_from_namespace namespace (function Bitfield br -> Some br | _ -> None)

let get_enumerations_from_namespace namespace =
  get_x_from_namespace namespace (function
    | Enumeration en -> Some en
    | _ -> None)

type parentRelationship =
  | NoParent
  | SameNamespaceParent of string
  | AnotherNamespaceParent of (string * string)

let map_entity_relationship this_ns parent =
  CCOption.map_or ~default:NoParent
    (fun parent ->
      let parent_ns, parent_name = map_entity_name this_ns parent in
      if this_ns = parent_ns then SameNamespaceParent parent_name
      else AnotherNamespaceParent (parent_ns, parent_name))
    parent

(** 
  sort classes by their dependencies on one another. only looks at parent-relationship in same namespace *)
let rec sort_by_dependencies ?(sorted_classes = []) = function
  | [] -> List.rev sorted_classes
  | all_classes -> (
      let free_classes, stuck_classes =
        List.partition
          (fun ((ns, _), (_, { parent; _ })) ->
            match map_entity_relationship ns parent with
            | NoParent -> true
            | AnotherNamespaceParent _ -> true
            | SameNamespaceParent parent_name ->
                List.exists
                  (fun ((_, name), (_, _)) -> name = parent_name)
                  sorted_classes)
          all_classes
      in
      match free_classes with
      | [] -> raise (Failure "Recursive definitions")
      | free_classes ->
          sort_by_dependencies
            ~sorted_classes:(List.concat [ free_classes; sorted_classes ])
            stuck_classes)

type typeMapping = {
  ml_type_name : string;
  ml_qualified_name : string;
  ml_value_to_gobj_value_macro : string -> string;
  gobj_value_to_ml_value_macro : string -> string;
  ml_arg_macro : string -> string;
}

type parameterMapping = {
  c_name : string;
  ml_name : string;
  type_mapping : typeMapping;
}

let calculate_type_values env = function
  | SimpleTypeRef "gunichar" ->
      Some
        ( "Uchar.t",
          "Uchar.t",
          (* FIXME: stored as ints but uses opaque type *)
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          fun v -> sprintf "%s" v )
  | SimpleTypeRef "gint8" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          fun v -> v )
  | SimpleTypeRef "guint8" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          fun v -> v )
  | SimpleTypeRef "gint16" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          fun v -> v )
  | SimpleTypeRef "guint16" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          fun v -> v )
  | SimpleTypeRef "gint32" ->
      Some
        ( "Int32.t",
          "Int32.t",
          (fun v -> sprintf "Int32_val(%s)" v),
          (fun v -> sprintf "caml_copy_int32(%s)" v),
          fun v -> v )
  | SimpleTypeRef "guint32" ->
      Some
        ( "Int32.t",
          "Int32.t",
          (fun v -> sprintf "Int32_val(%s)" v),
          (fun v -> sprintf "caml_copy_int32(%s)" v),
          fun v -> v )
  | SimpleTypeRef "gint64" ->
      Some
        ( "Int64.t",
          "Int64.t",
          (fun v -> sprintf "Int64_val(%s)" v),
          (fun v -> sprintf "caml_copy_int64(%s)" v),
          fun v -> v )
  | SimpleTypeRef "guint64" ->
      Some
        ( "Int64.t",
          "Int64.t",
          (fun v -> sprintf "Int64_val(%s)" v),
          (fun v -> sprintf "Val_int64(%s)" v),
          fun v -> v )
  | SimpleTypeRef "gfloat" ->
      Some
        ( "float",
          "float",
          (fun v -> sprintf "Double_val(%s)" v),
          (fun v -> sprintf "caml_copy_double(%s)" v),
          fun v -> v )
  | SimpleTypeRef "gdouble" ->
      Some
        ( "float",
          "float",
          (fun v -> sprintf "Double_val(%s)" v),
          (fun v -> sprintf "caml_copy_double(%s)" v),
          fun v -> v )
  | SimpleTypeRef "gboolean" ->
      Some
        ( "bool",
          "bool",
          (fun v -> sprintf "Bool_val(%s)" v),
          (fun v -> sprintf "(%s ? Val_true : Val_false)" v),
          fun v -> v )
  | SimpleTypeRef "filename" ->
      Some
        ( "string",
          "string",
          (fun v -> sprintf "String_val(%s)" v),
          (fun v -> sprintf "caml_copy_string(%s)" v),
          fun v -> v )
  | SimpleTypeRef "any" -> None
  | SimpleTypeRef "utf8" ->
      Some
        ( "string",
          "string",
          (fun v -> sprintf "String_val(%s)" v),
          (fun v -> sprintf "caml_copy_string(%s)" v),
          fun v -> v )
  | SimpleTypeRef "none" ->
      Some
        ( "unit",
          "unit",
          (fun _ -> "void"),
          (* is this correct? *)
          (fun _ -> "Val_unit"),
          fun v -> v )
  | SimpleTypeRef "GType" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Int_val(%s)" v),
          (fun v -> sprintf "Val_int(%s)" v),
          fun v -> v )
  | SimpleTypeRef x ->
      let ns, name = map_entity_name env.namespace x in
      CCOption.(
        let+ er, et = EntityMap.get (ns, name) env.all_entities in
        match et with
        | Class _ ->
            Some
              ( sprintf "[>`%s] obj" (c_type_name er),
                qualified_name env.namespace (ns, ml_name0 name),
                (fun v -> sprintf "GObject_val(%s)" v),
                (fun _ -> "void *"),
                fun v -> sprintf "%s#as_%s" v (c_type_name er) )
        | Bitfield _ ->
            Some
              ( "int",
                "int",
                (fun v -> sprintf "Int_val(%s)" v),
                (fun v -> sprintf "Val_int(%s)" v),
                fun v -> v )
        | Enumeration _ ->
            Some
              ( qualified_name env.namespace (ns, ml_name0 er.name),
                qualified_name env.namespace (ns, ml_name0 er.name),
                (fun v -> sprintf "%s_val(%s)" er.name v),
                (fun v -> sprintf "Val_%s(%s)" er.name v),
                fun v -> v )
        (* The following are secondary concerns (for now)
           as they appear to use different layouts and
           are harder to bind to *)
        | Callback _ -> None
        | Interface _ -> None
        | Record _ -> None
        | a ->
            raise
              (Failure
                 (sprintf "Could not calculate type values for typeref %s=%a" x
                    pp_entityType a)))
      |> CCOption.get_exn_or
           ("While calculating type values for " ^ x
          ^ " could not find it's complex entity in namespace " ^ env.namespace
           )
  | _ -> None

let opt_list_to_list_opt l =
  CCList.fold_right
    (fun b li ->
      match li with
      | Some li -> ( match b with Some b -> Some (b :: li) | None -> None)
      | None -> None)
    l (Some [])

let calculate_ml_params env parameters =
  parameters
  |> List.map (fun (parameter : parameterRecord) ->
         let c_name = escape_c_keyword parameter.name in
         let ml_name = escape_ml_keyword parameter.name in
         CCOption.(
           let+ ( ml_type_name,
                  ml_qualified_name,
                  ml_value_to_gobj_value_macro,
                  gobj_value_to_ml_value_macro,
                  ml_arg_macro ) =
             calculate_type_values env parameter.type_
           in

           {
             c_name;
             ml_name;
             type_mapping =
               {
                 ml_type_name;
                 ml_qualified_name;
                 ml_value_to_gobj_value_macro;
                 gobj_value_to_ml_value_macro;
                 ml_arg_macro;
               };
           }))
  |> opt_list_to_list_opt

let calculate_ml_return_value env (retvalue : returnValueRecord) =
  CCOption.(
    let+ ( ml_type_name,
           ml_qualified_name,
           ml_value_to_gobj_value_macro,
           gobj_value_to_ml_value_macro,
           ml_arg_macro ) =
      calculate_type_values env retvalue.type_
    in
    {
      ml_type_name;
      ml_qualified_name;
      ml_value_to_gobj_value_macro;
      gobj_value_to_ml_value_macro;
      ml_arg_macro;
    })

let make_ml_binding_params_string params =
  match params with
  | [] -> "unit"
  | params ->
      CCList.to_string ~sep:" -> " (fun p -> p.type_mapping.ml_type_name) params

let make_ml_constructor_params_string params =
  match params with
  | [] -> "()"
  | _ ->
      CCList.to_string ~sep:" "
        (fun param ->
          sprintf "(%s: %s)" param.ml_name param.type_mapping.ml_qualified_name)
        params

let make_ml_args params =
  match List.length params with
  | 0 -> "()"
  | _ ->
      params
      |> CCList.to_string ~sep:" " (fun (param : parameterMapping) ->
             param.type_mapping.ml_arg_macro param.ml_name)

let print_method_binding ~ml ~namespace ~class_name ~method_name ~params
    ~return_value ~env =
  let mlfunc = escape_ml_keyword method_name in
  let params = calculate_ml_params env params in
  let return_type = calculate_ml_return_value env return_value in
  match (params, return_type) with
  | Some params, Some return_type -> (
      let param_string = make_ml_binding_params_string params in
      let c_func = make_c_func_name namespace class_name method_name in
      match List.length params with
      | 0 | 1 | 2 | 3 | 4 | 5 ->
          ml
            (sprintf "  external %s: %s -> %s = \"%s\"" mlfunc param_string
               return_type.ml_type_name c_func)
      | _ ->
          let bytecode_func = c_func ^ "_bytecode" in
          ml
            (sprintf "  external %s: %s -> %s = \"%s\" \"%s\"" mlfunc
               param_string return_type.ml_type_name bytecode_func c_func))
  | _ -> ()

let print_class_constructor_bindings ml namespace class_name constructors env =
  List.iter
    (fun (constructor : classConstructorRecord) ->
      print_method_binding ~ml ~namespace ~class_name
        ~method_name:constructor.name ~params:constructor.parameters
        ~return_value:constructor.return_value ~env)
    constructors

let print_class_method_bindings ml namespace class_name methods env =
  List.iter
    (fun (m : classMethodRecord) ->
      print_method_binding ~ml ~namespace ~class_name ~method_name:m.name
        ~params:m.parameters ~return_value:m.return_value ~env)
    methods

(** print the GObject class module entries, which contains the bindings to C function implementations *)
let print_class_bindings ml all_classes env =
  List.iter
    (fun ((ns, name), (er, (cl : classRecord))) ->
      ml "";
      ml (Format.sprintf "module %s_ = struct" name);
      ml
        (Format.sprintf "  let upcast: [>`%s] obj -> %s = Obj.magic"
           (c_type_name er) (ml_name er.name));
      print_class_constructor_bindings ml ns name cl.constructor env;
      print_class_method_bindings ml ns name cl.methods env;
      ml "end")
    all_classes

let print_class_definitions ml all_classes =
  List.iter
    (fun ((ns, _), (er, cl)) ->
      ml
        (Format.sprintf "class %s  (self: %s) =" (ml_name0 er.name)
           (ml_name er.name));
      ml "  object";
      Option.iter
        (fun parent ->
          let parent_ns, parent_name = map_entity_name ns parent in
          let qualifier = if parent_ns <> ns then parent_ns ^ "." else "" in
          ml
            (Format.sprintf "    inherit %s (%s.upcast self)"
               (qualifier ^ ml_name0 parent_name)
               (qualifier ^ parent_name ^ "_")))
        cl.parent;
      ml (Format.sprintf "    method as_%s = self" (c_type_name er));
      ml "  end")
    all_classes

let print_class_constructor ml namespace class_name
    (constructor : classConstructorRecord) env =
  let mlfunc = escape_ml_keyword constructor.name in
  let params = calculate_ml_params env constructor.parameters in
  match params with
  | Some params ->
      let param_string = make_ml_constructor_params_string params in
      let args_text = make_ml_args params in
      let c_func = make_c_func_name namespace class_name constructor.name in
      ml
        (sprintf "  let %s %s = new %s (%s_.%s %s)" mlfunc param_string
           (ml_name0 class_name) class_name mlfunc args_text)
  | _ -> ml (sprintf "(* constructor skipped %s *)" constructor.name)

let print_class_constructor_modules ml all_classes env =
  List.iter
    (fun ((ns, _), (er, (cl : classRecord))) ->
      ml "";
      ml (sprintf "module %s = struct" er.name);
      List.iter
        (fun (c : classConstructorRecord) ->
          print_class_constructor ml ns er.name c env)
        cl.constructor;
      ml "end")
    all_classes

let process_namespaces namespaces =
  let all_classes_by_entity_name =
    namespaces
    |> CCList.flat_map get_classes_from_namespace
    |> Entity.EntityMap.of_list
  in
  let all_entities = Entity.make_all_entities namespaces in
  (* let module Env_Factory = (val (make_env_factory namespaces)) in *)
  namespaces
  |> List.iter (fun namespace ->
         match namespace with
         | Namespace (({ name; _ } as ns), _) as n ->
             let ml_file = Out_channel.open_text (name ^ ".ml") in
             let ml = Printf.fprintf ml_file "%s\n" in
             let c_file = Out_channel.open_text ("ml_" ^ name ^ ".c") in
             let cf = Printf.fprintf c_file "%s\n" in
             print_ml_start ml;
             print_c_start cf;

             let all_classes = get_classes_from_namespace n in
             print_class_ancestors ml all_classes all_classes_by_entity_name;

             let all_bitfields = get_bitfields_from_namespace n in
             print_bitfields ml all_bitfields;

             let all_enumerations = get_enumerations_from_namespace n in
             print_enumerations ml all_enumerations;

             let env = { namespace = name; all_entities } in

             print_class_bindings ml all_classes env;
             let all_classes_ordered = sort_by_dependencies all_classes in
             print_class_definitions ml all_classes_ordered;
             print_class_constructor_modules ml all_classes_ordered env;
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
           Printf.eprintf "Error reading %s: %s\n" filename x;
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