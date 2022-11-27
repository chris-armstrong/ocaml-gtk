type attribute = string * string [@@deriving show]

type arrayTypeRecord = {
  length : int option;
  zero_terminated : bool;
  fixed_size : int option;
}
[@@deriving show]

type typeRef =
  | SimpleTypeRef of string
  | ComplexTypeRef of string * typeRef list
  | ArrayTypeRef of arrayTypeRecord * typeRef
[@@deriving show]

type namespaceRecord = {
  name : string;
  version : string;
  sharedLibrary : string;
  prefix : string;
}
[@@deriving show]

type constantRecord = { value : string; type_ : typeRef } [@@deriving show]

type transferOwnership =
  | TransferOwnershipNone
  | TransferOwnershipFull
  | TransferOwnershipContainer
[@@deriving show]

type returnValueRecord = {
  transfer_ownership : transferOwnership;
  type_ : typeRef;
  attributes : attribute list;
}
[@@deriving show]

type parameterRecord = {
  name : string;
  transfer_ownership : transferOwnership;
  type_ : typeRef;
}
[@@deriving show]

type callbackRecord = {
  return_value : returnValueRecord;
  parameters : parameterRecord list;
}
[@@deriving show]

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

type signalWhen = SignalFirst | SignalLast | SignalCleanup [@@deriving show]

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
type fieldRecord = { name : string; type_ : typeRef } [@@deriving show]

type virtualMethodRecord = {
  name : string;
  offset : int;
  invoker : string option;
  return_value : returnValueRecord;
  parameters : parameterRecord list;
  attributes : attribute list;
}
[@@deriving show]

type classRecord = {
  parent : string option;
  abstract : bool;
  implements : string list;
  fields : fieldRecord list;
  attributes : attribute list;
  constructor : classConstructorRecord list;
  methods : classMethodRecord list;
  functions : functionRecord list;
  properties : classPropertyRecord list;
  signals : signalRecord list;
  virtual_methods : virtualMethodRecord list;
}
[@@deriving show]

type recordRecord = {
  fields : fieldRecord list;
  constructor : classConstructorRecord list;
  methods : classMethodRecord list;
  functions : functionRecord list;
}
[@@deriving show]

type interfaceRecord = {
  attributes: attribute list;
  prerequisites: string list;
  methods : classMethodRecord list;
  functions : functionRecord list;
  properties : classPropertyRecord list;
  signals : signalRecord list;
  virtual_methods : virtualMethodRecord list;
}
[@@deriving show]

type memberRecord = {
  name: string;
  value: string;
  attributes: attribute list;
}
[@@deriving show]

type bitfieldRecord = {
  members: memberRecord list;
}
[@@deriving show]

type entityDescriptor = {
  name: string;
  glibTypeName: string option;
}
[@@deriving show]

type enumerationRecord = {
  members: memberRecord list;
}
[@@deriving show]

type entityType =
  | Constant of constantRecord
  | Class of classRecord
  | Callback of callbackRecord
  | Enumeration of enumerationRecord
  | Interface of interfaceRecord
  | Bitfield of bitfieldRecord
  | Record of recordRecord
[@@deriving show]

type namespaceType = Namespace of namespaceRecord * (entityDescriptor * entityType) list
[@@deriving show]

type includeType = Include of string * string [@@deriving show]

type repositoryType = Repository of namespaceType list * includeType list
[@@deriving show]
