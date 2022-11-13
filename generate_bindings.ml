open Xmlm
open Xml_helpers

type arrayTypeRecord = {
  length : int option;
  zero_terminated : bool;
  fixed_size : int option;
}
[@@deriving show]

type typeRef =
  | SimpleTypeRef of string
  | ArrayTypeRef of string * arrayTypeRecord
[@@deriving show]

type namespaceRecord = {
  name : string;
  version : string;
  sharedLibrary : string;
  prefix : string;
}
[@@deriving show]

type constantRecord = { value : string; type_ : typeRef } [@@deriving show]

type transferOwnership = TransferOwnershipNone | TransferOwnershipFull
[@@deriving show]

type returnValueRecord = {
  transfer_ownership : transferOwnership;
  type_ : typeRef;
}
[@@deriving show]

type parameterRecord = {
  name : string;
  transfer_ownership : transferOwnership;
  type_ : typeRef;
}
[@@deriving show]

type attribute = string * string [@@deriving show]

type classMethodRecord = {
  name : string;
  attributes : attribute list;
  return_value : returnValueRecord;
  parameters : parameterRecord list;
}
[@@deriving show]

type classPropertyRecord = {
  name : string;
  writable : bool;
  construct : bool;
  construct_only : bool;
  getter : string option;
  transfer_ownership : transferOwnership;
  type_name : typeRef;
}
[@@deriving show]

type signalWhen = SignalFirst | SignalLast [@@deriving show]

type signalRecord = {
  name : string;
  when_ : signalWhen;
  return_value : returnValueRecord;
  parameters : parameterRecord list;
}
[@@deriving show]

type functionRecord = {
  name : string;
  return_value : returnValueRecord;
  parameters : parameterRecord list;
}
[@@deriving show]

type classConstructorRecord = functionRecord [@@deriving show]

type fieldRecord = { name: string; type_: typeRef }
[@@deriving show]

type virtualMethodRecord = {
  name : string;
  offset: int;
invoker: string option;
return_value: returnValueRecord;
parameters: parameterRecord list;
}[@@deriving show]

type classRecord = {
  parent : string;
  abstract : bool;
  implements : string list;
  fields: fieldRecord list;
  attributes : attribute list;
  constructor : classConstructorRecord list;
  methods : classMethodRecord list;
  functions : functionRecord list;
  properties : classPropertyRecord list;
  signals : signalRecord list;
  virtual_methods: virtualMethodRecord list;
}
[@@deriving show]

type entityType =
  | Constant of string * constantRecord
  | Class of string * classRecord
  | Interface of string
  | Record of string
  | Enumeration of string
  | StringEntity of string
[@@deriving show]

type namespaceType = Namespace of namespaceRecord * entityType list
[@@deriving show]

type includeType = Include of string * string [@@deriving show]

type repositoryType = Repository of namespaceType list * includeType list
[@@deriving show]

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

let read_type i ~attrs:_ =
  let res =
    match input i with
    | `El_start ((_, "type"), attrs) -> SimpleTypeRef (attr "name" attrs)
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
        let type_name = tag "type" i |> attr "name" in
        ArrayTypeRef (type_name, { length; zero_terminated; fixed_size })
    | s -> raise (expected_start_tag "array or type" s)
  in
  let _ = input i in
  res

let read_constant i =
  block
    (fun i ~attrs ->
      Constant
        ( attr "name" attrs,
          { value = attr "value" attrs; type_ = read_type i ~attrs } ))
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
  | s ->
      raise
        (Failure (Format.sprintf "Unknown transfer-ownership value: \"%s\"" s))

let read_return_value i =
  block
    (fun i ~attrs ->
      {
        type_ = read_type i ~attrs;
        transfer_ownership = read_transfer_ownership attrs;
      })
    "return-value" i

let rec read_parameters_list ?(parameters = []) i =
  match
    block_opt
      (fun i ~attrs ->
        {
          name = attr "name" attrs;
          type_ = read_type i ~attrs;
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
        let attributes = read_attributes i in
        let return_value = read_return_value i in
        let parameters = read_parameters i in
        { name = attr "name" attrs; attributes; return_value; parameters })
      "method" i
  with
  | Some method_ -> method_ :: read_methods ~methods i
  | None -> methods

let rec read_virtual_methods ?(methods = []) i =
  match
    block_opt
      (fun i ~attrs ->
        let offset = (attr "offset" attrs) |> int_of_string in
        let invoker = (attr_opt "invoker" attrs) in
        let return_value = read_return_value i in
        let parameters = read_parameters i in
        { name = attr "name" attrs; offset; invoker; return_value; parameters })
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
          writable = attr "writable" attrs = "1";
          construct =
            Option.value (attr_opt "construct" attrs) ~default:"0" = "1";
          construct_only =
            Option.value (attr_opt "construct-only" attrs) ~default:"0" = "1";
          transfer_ownership = read_transfer_ownership attrs;
          getter = attr_opt "getter" attrs;
          type_name = read_type i ~attrs;
        })
      "property" i
  with
  | Some property -> property :: read_properties ~properties i
  | None -> properties

let read_signal_when attrs =
  match attr "when" attrs with
  | "FIRST" -> SignalFirst
  | "LAST" -> SignalLast
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

let rec read_fields ?(fields = []) i = match block_opt
  (fun i ~attrs ->
    let name = attr "name" attrs in
    let type_ = read_type i ~attrs in
    { name; type_ }) "field" i with
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
        ( attr "name" attrs,
          {
            parent = attr "parent" attrs;
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

let read_entity name i =
  match name with
  | "constant" -> Some (read_constant i)
  | "class" -> Some (read_class i)
  | _ ->
      let _ = ignore_block i in
      None

let rec read_entities ?(entities : entityType list = []) i =
  match peek i with
  | `El_start ((_, name), _) -> (
      let entity = read_entity name i in
      match entity with
      | Some entity -> entity :: read_entities ~entities i
      | None -> read_entities ~entities i)
  | _ -> entities

let rec read_namespaces ?(namespaces : namespaceType list = []) i =
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
  | Some namespace -> namespace :: read_namespaces ~namespaces i
  | None -> namespaces

let read_repository input =
  let includes = read_includes input in
  let namespaces = read_namespaces input in
  Repository (namespaces, includes)

let read_root i =
  let _ = input i in
  match input i with
  | `El_start ((_, "repository"), _) -> read_repository i
  | _ -> raise (Failure "no repository element at root")

let _in = open_source ~ns:namespace_gobject (Array.get Sys.argv 1)
let rep = read_root _in;;

Format.printf "structure %a\n" pp_repositoryType rep
