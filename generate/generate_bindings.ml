open Parse_gobject_model
open Gobject_model
open Pretty_print
open Escape
open Entity
open Dependencies


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

(* let type_remaining_by_classes namespace class_names
  (owning_ns, owning_name) x =
  List.exists (fun (ns, name) -> name = x && namespace = ns && not (owning_ns = namespace && owning_name = x)) class_names *)


let pp_typeRef_list = Format.(pp_print_list ~pp_sep:pp_comma pp_typeRef)

let rec extract_ref_types = function
  | SimpleTypeRef x -> [x]
  | ArrayTypeRef (_, refs) -> extract_ref_types refs
  | ComplexTypeRef (_, refs) -> CCList.flat_map extract_ref_types refs

let pp_string_list = Format.(pp_print_list ~pp_sep:pp_comma pp_print_string)


let dependencies_for_class = (fun ((ns, _), (_, { parent; constructor; methods; _ })) ->
    let parent_dependency = (match map_entity_relationship ns parent with
    | NoParent -> []
    | AnotherNamespaceParent _ -> []
    | SameNamespaceParent parent_name -> [parent_name]) in
    let constructor_dependencies = CCList.flat_map (fun (constructor: classConstructorRecord)  ->
      let parameter_types = CCList.flat_map (fun (p: parameterRecord) -> extract_ref_types p.type_) constructor.parameters in
      let return_type = extract_ref_types constructor.return_value.type_ in
      (List.concat [return_type;parameter_types])
    ) constructor in
    let method_dependencies = methods |> CCList.flat_map (fun (method_: classMethodRecord) ->
      let parameter_types = CCList.flat_map (fun (p: parameterRecord) -> extract_ref_types p.type_) method_.parameters in
      let return_type = extract_ref_types method_.return_value.type_ in
      (List.concat [return_type;parameter_types])
      ) in
    [parent_dependency; constructor_dependencies; method_dependencies] |> List.concat
  )


type typeMapping = {
  ml_type_name : string;
  ml_qualified_name : string;
  ml_value_to_gobj_value_macro : string -> string;
  gobj_value_to_ml_value_macro : string -> string;
  ml_arg_macro : string -> string;
  ml_return_type_macro: string -> string;
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
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "gint8" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "guint8" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "gint16" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "guint16" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Long_val(%s)" v),
          (fun v -> sprintf "Val_long(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "gint32" ->
      Some
        ( "Int32.t",
          "Int32.t",
          (fun v -> sprintf "Int32_val(%s)" v),
          (fun v -> sprintf "caml_copy_int32(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "guint32" ->
      Some
        ( "Int32.t",
          "Int32.t",
          (fun v -> sprintf "Int32_val(%s)" v),
          (fun v -> sprintf "caml_copy_int32(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "gint64" ->
      Some
        ( "Int64.t",
          "Int64.t",
          (fun v -> sprintf "Int64_val(%s)" v),
          (fun v -> sprintf "caml_copy_int64(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "guint64" ->
      Some
        ( "Int64.t",
          "Int64.t",
          (fun v -> sprintf "Int64_val(%s)" v),
          (fun v -> sprintf "Val_int64(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "gfloat" ->
      Some
        ( "float",
          "float",
          (fun v -> sprintf "Double_val(%s)" v),
          (fun v -> sprintf "caml_copy_double(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "gdouble" ->
      Some
        ( "float",
          "float",
          (fun v -> sprintf "Double_val(%s)" v),
          (fun v -> sprintf "caml_copy_double(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "gboolean" ->
      Some
        ( "bool",
          "bool",
          (fun v -> sprintf "Bool_val(%s)" v),
          (fun v -> sprintf "(%s ? Val_true : Val_false)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "filename" ->
      Some
        ( "string",
          "string",
          (fun v -> sprintf "String_val(%s)" v),
          (fun v -> sprintf "caml_copy_string(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "any" -> None
  | SimpleTypeRef "utf8" ->
      Some
        ( "string",
          "string",
          (fun v -> sprintf "String_val(%s)" v),
          (fun v -> sprintf "caml_copy_string(%s)" v),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "none" ->
      Some
        ( "unit",
          "unit",
          (fun _ -> "void"),
          (* is this correct? *)
          (fun _ -> "Val_unit"),
          (fun v -> v),
          fun v -> v )
  | SimpleTypeRef "GType" ->
      Some
        ( "int",
          "int",
          (fun v -> sprintf "Int_val(%s)" v),
          (fun v -> sprintf "Val_int(%s)" v),
          (fun v -> v),
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
                (fun v -> sprintf "%s#as_%s" v (c_type_name er)),
                (fun v -> sprintf "new %s (%s)" (ml_name0 er.name) v) )
        | Bitfield _ ->
            Some
              ( "int",
                "int",
                (fun v -> sprintf "Int_val(%s)" v),
                (fun v -> sprintf "Val_int(%s)" v),
                (fun v -> v),
                fun v -> v )
        | Enumeration _ ->
            Some
              ( qualified_name env.namespace (ns, ml_name0 er.name),
                qualified_name env.namespace (ns, ml_name0 er.name),
                (fun v -> sprintf "%s_val(%s)" er.name v),
                (fun v -> sprintf "Val_%s(%s)" er.name v),
                (fun v -> v),
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
                  ml_arg_macro,
                  ml_return_type_macro ) =
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
                 ml_return_type_macro;
               };
           }))
  |> opt_list_to_list_opt

let calculate_ml_return_value env (retvalue : returnValueRecord) =
  CCOption.(
    let+ ( ml_type_name,
           ml_qualified_name,
           ml_value_to_gobj_value_macro,
           gobj_value_to_ml_value_macro,
           ml_arg_macro,
           ml_return_type_macro ) =
      calculate_type_values env retvalue.type_
    in
    {
      ml_type_name;
      ml_qualified_name;
      ml_value_to_gobj_value_macro;
      gobj_value_to_ml_value_macro;
      ml_arg_macro;
      ml_return_type_macro;
    })

let make_ml_binding_params_string params =
  match params with
  | [] -> "unit"
  | params ->
      CCList.to_string ~sep:" -> " (fun p -> p.type_mapping.ml_type_name) params

(** Convert parameters to a string for a class constructor wrapper (parameters) *)
let make_ml_constructor_params_string params =
  match params with
  | [] -> "()"
  | _ ->
      CCList.to_string ~sep:" "
        (fun param ->
          sprintf "(%s: %s)" param.ml_name param.type_mapping.ml_qualified_name)
        params


(** Convert parameters to a string for a class constructor wrapper (arguments to binding) *)
let make_ml_constructor_args_string params =
  match List.length params with
  | 0 -> "()"
  | _ ->
      params
      |> CCList.to_string ~sep:" " (fun (param : parameterMapping) ->
             param.type_mapping.ml_arg_macro param.ml_name)

(** Convert parameters to a string for a class method wrapper (parameters) *)
let make_ml_method_params_string params =
  CCList.to_string ~sep:" "
    (fun param ->
      sprintf "(%s: %s)" param.ml_name param.type_mapping.ml_qualified_name)
    params

(** Convert parameters to a string for a class method wrapper (arguments to binding) *)
let make_ml_method_args_string params =
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
      let object_parameter = {
        transfer_ownership= TransferOwnershipNone;
        name= "instance_";
        type_= SimpleTypeRef class_name;
      } in
      print_method_binding ~ml ~namespace ~class_name ~method_name:m.name
        ~params:(object_parameter::m.parameters) ~return_value:m.return_value ~env)
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

let print_class_definition_parent ml namespace parent =
  Option.iter
    (fun parent ->
      let parent_ns, parent_name = map_entity_name namespace parent in
      let parent_ml_class_name = ml_name0 parent_name in
      let parent_ml_module_name = parent_name ^ "_" in
      let qualifier = if parent_ns <> namespace then parent_ns ^ "." else "" in
      ml
        (Format.sprintf "    inherit %s (%s.upcast self)"
            (qualifier ^ parent_ml_class_name)
            (qualifier ^ parent_ml_module_name)))
    parent

let print_class_definition_methods ml class_name methods env =
  List.iter (
    fun (constructor: classMethodRecord) ->
      let method_name = (constructor.name |> escape_ml_keyword) in
      let params = calculate_ml_params env constructor.parameters in
      let return_type = calculate_ml_return_value env constructor.return_value in
      match params, return_type with
      | Some params, Some return_type ->
        let param_string = make_ml_method_params_string params in
        let args_string = make_ml_method_args_string params in
        let body = return_type.ml_return_type_macro (sprintf "%s_.%s self %s" class_name method_name args_string) in
        ml (sprintf "    method %s%s = %s" method_name param_string body);
      | _ -> ml ("(* skipped method " ^ method_name ^ " due to unresolveable parameters / return type *)")
  ) methods

let print_class_definition_inner ml class_ env =
  let ((ns, class_name), (er, cl)) = class_ in
  ml
    (Format.sprintf "%s  (self: %s) =" (ml_name0 class_name)
        (ml_name class_name));
  ml "  object";
  print_class_definition_parent ml ns cl.parent;
  ml (Format.sprintf "    method as_%s = self" (c_type_name er));
  print_class_definition_methods ml er.name cl.methods env;
  ml "  end"

let sort_by_inheritance class_entities = class_entities |> List.sort (fun ((_, lname), (_, l)) ((_, rname), (_, r)) ->
  match l.parent, r.parent with
  | Some lparent, Some rparent -> if lparent = rname then 1 else if rparent = lname then -1 else 0
  | Some lparent, None -> if (lparent = rname) then 1 else 0
  | None, Some rparent -> if (rparent = lname) then -1 else 0
  | None , None -> 0
  )

let print_class_definitions ml all_classes env =
  List.iter
    (fun record -> match record with
      | Standalone class_ ->
        (ml "class";
        print_class_definition_inner ml class_ env;)
      | Recursive classes ->
        ml "class";
        classes |> sort_by_inheritance |> List.iteri (fun i class_ ->
          if i > 0 then ml "  and";
          print_class_definition_inner ml class_ env;
        );

      )
    all_classes

let print_class_constructor ml namespace class_name
    (constructor : classConstructorRecord) env =
  let mlfunc = escape_ml_keyword constructor.name in
  let params = calculate_ml_params env constructor.parameters in
  match params with
  | Some params ->
      let param_string = make_ml_constructor_params_string params in
      let args_text = make_ml_constructor_args_string params in
      let c_func = make_c_func_name namespace class_name constructor.name in
      ml
        (sprintf "  let %s %s = new %s (%s_.%s %s)" mlfunc param_string
           (ml_name0 class_name) class_name mlfunc args_text)
  | _ -> ml (sprintf "(* constructor skipped %s *)" constructor.name)

let print_class_constructor_module_inner ml ((ns, _), (er, (cl: classRecord))) env =
      ml "";
      ml (sprintf "module %s = struct" er.name);
      List.iter
        (fun (c : classConstructorRecord) ->
          print_class_constructor ml ns er.name c env)
        cl.constructor;
      ml "end"

let print_class_constructor_modules ml all_classes env =
  List.iter
    (function
      | Standalone class_ -> print_class_constructor_module_inner ml class_ env
      | Recursive classes -> List.iter (fun x -> print_class_constructor_module_inner ml x env) classes
      )
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
             let all_classes_ordered = sort_by_dependencies dependencies_for_class all_classes in
             print_class_definitions ml all_classes_ordered env;
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


let _ = generate ()