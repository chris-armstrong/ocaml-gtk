open Xmlm
open Xml_helpers
open Gobject_model

let namespace_gobject = function
  | "http://www.gtk.org/introspection/core/1.0" -> Some "core"
  | "http://www.gtk.org/introspection/c/1.0" -> Some "c"
  | "http://www.gtk.org/introspection/glib/1.0" -> Some "glib"
  | _ -> None

let rec read_includes ?(includes : includeType list = []) i =
  match tag_opt "include" i with
  | Some attrs ->
      Include (attr "name" attrs, attr "version" attrs)
      :: read_includes ~includes i
  | None -> includes

let rec read_type_ i = match input i with
  | `El_start ((_, "type"), attrs) ->
      let name = attr "name" attrs in
      let inner_types = read_inner_types i in
      let res = (match inner_types with
        | [] -> SimpleTypeRef name
        | _ -> ComplexTypeRef (name , inner_types)
      ) in
      let _ = input i in
      res
  | `El_start ((_, "array"), attrs) ->
        let length = attr_opt "length" attrs |> Option.map int_of_string in
        let zero_terminated =
          attr_opt "zero-terminated" attrs
          |> Option.map (fun x -> x = "1")
          |> Option.value ~default:false
        in
        let fixed_size =
          attr_opt "fixed-size" attrs |> Option.map int_of_string
        in
        let inner_type = read_type_ i in
        let _ = input i in
        ArrayTypeRef ({ length; zero_terminated; fixed_size }, inner_type)
  | _ -> raise (Failure "expected type or array tag")
and
read_inner_types ?(types = []) i = match peek i with
    | `El_start ((_, "type"), _)
    | `El_start ((_, "array"), _) -> let inner = (read_type_ i) in
      read_inner_types ~types:(inner :: types) i
    | `El_end -> types
    | _ -> raise (Failure "unknown")

let read_type i = read_type_ i

let read_constant i =
  block
    (fun i ~attrs ->
      Constant
        (
          { value = attr "value" attrs; type_ = read_type i } ))
    "constant" i

let rec read_attributes ?(attributes = []) i =
  match tag_opt "attribute" i with
  | Some attrs ->
      (attr "name" attrs, attr "value" attrs) :: read_attributes ~attributes i
  | None -> attributes

let rec read_implements ?(implements = []) i =
  match tag_opt "implements" i with
  | Some attrs -> attr "name" attrs :: read_implements ~implements i
  | None -> implements

let read_transfer_ownership attrs =
  match attr "transfer-ownership" attrs with
  | "none" -> TransferOwnershipNone
  | "full" -> TransferOwnershipFull
  | "container" -> TransferOwnershipContainer
  | s ->
      raise
        (Failure (Format.sprintf "Unknown transfer-ownership value: \"%s\"" s))

let read_return_value i =
  block
    (fun i ~attrs ->
      let attributes = read_attributes i in
      {
        transfer_ownership = read_transfer_ownership attrs;
        type_ = read_type i ;
        attributes;
      })
    "return-value" i

let rec read_parameters_list ?(parameters = []) i =
  match
    block_opt
      (fun i ~attrs ->
        {
          name = attr "name" attrs;
          type_ = read_type i ;
          transfer_ownership = read_transfer_ownership attrs;
        })
      "parameter" i
  with
  | Some parameter -> parameter :: read_parameters_list ~parameters i
  | None -> parameters

let read_parameters i =
  match block_opt (fun i ~attrs:_ -> read_parameters_list i) "parameters" i with
  | Some records -> records
  | None -> []

let rec read_constructors ?(constructors = []) i =
  match
    block_opt
      (fun i ~attrs ->
        let return_value = read_return_value i in
        let parameters = read_parameters i in
        { name = attr "name" attrs; return_value; parameters })
      "constructor" i
  with
  | Some constructor -> constructor :: read_constructors ~constructors i
  | None -> constructors

let rec read_methods ?(methods = []) i =
  match
    block_opt
      (fun i ~attrs ->
        let name = attr "name" attrs in
        let attributes = read_attributes i in
        let return_value = read_return_value i in
        let parameters = read_parameters i in
        { name; attributes; return_value; parameters })
      "method" i
  with
  | Some method_ -> method_ :: read_methods ~methods i
  | None -> methods

let rec read_virtual_methods ?(methods = []) i =
  match
    block_opt
      (fun i ~attrs ->
        let offset = attr "offset" attrs |> int_of_string in
        let invoker = attr_opt "invoker" attrs in
        let attributes = read_attributes i in
        let return_value = read_return_value i in
        let parameters = read_parameters i in
        { name = attr "name" attrs; offset; attributes; invoker; return_value; parameters })
      "virtual-method" i
  with
  | Some method_ -> method_ :: read_virtual_methods ~methods i
  | None -> methods

let rec read_properties ?(properties = []) i =
  match
    block_opt
      (fun i ~attrs ->
        {
          name = attr "name" attrs;
          writable =
            attr_opt "writable" attrs |> Option.value ~default:"0" = "1";
          construct =
            Option.value (attr_opt "construct" attrs) ~default:"0" = "1";
          construct_only =
            Option.value (attr_opt "construct-only" attrs) ~default:"0" = "1";
          transfer_ownership = read_transfer_ownership attrs;
          getter = attr_opt "getter" attrs;
          type_name = read_type i ;
        })
      "property" i
  with
  | Some property -> property :: read_properties ~properties i
  | None -> properties

let read_signal_when attrs =
  match attr "when" attrs with
  | "FIRST" -> SignalFirst
  | "LAST" -> SignalLast
  | "CLEANUP" -> SignalCleanup
  | _ as when_ -> raise (Failure ("Unknown signal when value " ^ when_))

let rec read_signals ?(signals = []) i =
  match
    block_opt
      (fun i ~attrs ->
        let return_value = read_return_value i in
        let parameters = read_parameters i in
        {
          name = attr "name" attrs;
          when_ = read_signal_when attrs;
          return_value;
          parameters;
        })
      "signal" i
  with
  | Some signal -> signal :: read_signals ~signals i
  | None -> signals

let rec read_functions ?(functions = []) i =
  match
    block_opt
      (fun i ~attrs ->
        let return_value = read_return_value i in
        let parameters = read_parameters i in
        { name = attr "name" attrs; parameters; return_value })
      "function" i
  with
  | Some func -> func :: read_functions ~functions i
  | None -> functions

let rec read_fields ?(fields = []) i =
  match
    block_opt
      (fun i ~attrs ->
        let name = attr "name" attrs in
        let type_ = read_type i in
        { name; type_ })
      "field" i
  with
  | Some field -> field :: read_fields ~fields i
  | None -> fields

let read_class i =
  block
    (fun i ~attrs ->
      let attributes = read_attributes i in
      let implements = read_implements i in
      let fields = read_fields i in
      let constructor = read_constructors i in
      let functions = read_functions i in
      let methods = read_methods i in
      let properties = read_properties i in
      let signals = read_signals i in
      let virtual_methods = read_virtual_methods i in
      Class
        (
          {
            parent = attr_opt "parent" attrs;
            abstract = false (* FIXME *);
            attributes;
            implements;
            fields;
            constructor;
            functions;
            methods;
            properties;
            signals;
            virtual_methods;
          } ))
    "class" i

let read_entity tag attrs i =
  let descriptor = {
    name = attr "name" attrs;
    glibTypeName = attr_opt "type-name" attrs;
  } in
  match tag with
  | "constant" -> Some (descriptor, read_constant i)
  | "class" -> Some (descriptor, read_class i)
  | _ ->
      let _ = ignore_block i in
      None

let rec read_entities ?(entities = []) i =
  match peek i with
  | `El_start ((_, tag), attrs) -> (
      (* Printf.printf "Reading entity %s\n" name; *)
      let entity = read_entity tag attrs i in
      match entity with
      | Some entity -> read_entities ~entities:(entity::entities) i
      | None -> read_entities ~entities i)
  | _ ->
      (* Format.printf "End read entities: %a\n" pp_signal s; *)
      List.rev entities

let rec read_namespaces ?(namespaces = []) i =
  match
    block_opt
      (fun i ~attrs ->
        Namespace
          ( {
              name = attr "name" attrs;
              version = attr "version" attrs;
              sharedLibrary = attr "shared-library" attrs;
              prefix = attr "prefix" attrs;
            },
            read_entities i ))
      "namespace" i
  with
  | Some namespace -> read_namespaces ~namespaces:(namespace::namespaces) i
  | None -> namespaces

let read_repository input =
  let includes = read_includes input in
  let namespaces = read_namespaces input in
  Repository (namespaces, includes)

let read i =
  let _ = input i in
  match input i with
  | `El_start ((_, "repository"), _) -> read_repository i
  | _ -> raise (Failure "no repository element at root")