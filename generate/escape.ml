let ml_keywords =
  [
    "and";
    "as";
    "assert";
    "asr";
    "begin";
    "class";
    "constraint";
    "do";
    "done";
    "downto";
    "else";
    "end";
    "exception";
    "external";
    "false";
    "for";
    "fun";
    "function";
    "functor";
    "if";
    "in";
    "include";
    "inherit";
    "initializer";
    "land";
    "lazy";
    "let";
    "lor";
    "lsl";
    "lsr";
    "lxor";
    "match";
    "method";
    "mod";
    "module";
    "mutable";
    "new";
    "nonrec";
    "object";
    "of";
    "open";
    "or";
    "private";
    "rec";
    "sig";
    "struct";
    "then";
    "to";
    "true";
    "try";
    "type";
    "unit";
    "val";
    "virtual";
    "when";
    "while";
    "with";
  ]

let escape_ml_keyword name =
  match List.exists (( = ) name) ml_keywords with
  | true -> name ^ "_"
  | false -> name

let escape_c_keyword name =
  (if name = "value" then "value_" else name)

let pascal_case_to_snake_case: (string -> string) = fun name ->
  name |> String.to_seq
  |> Seq.mapi (fun i c ->
         if i = 0 then ((Char.lowercase_ascii c) |> Char.escaped)
         else
           match c <= 'Z' with
           | true -> "_" ^ Char.escaped (Char.lowercase_ascii c)
           | false -> Char.escaped c)
  |> List.of_seq |> (String.concat "")

let ml_name0 name = name |> pascal_case_to_snake_case |> escape_ml_keyword
let ml_name name = String.cat (ml_name0 name) "_"

let cs_name name = name |> CCString.mapi (fun i c -> 
  match i with
  | 0 -> CCChar.uppercase_ascii c 
  | _ -> c) |> (fun n ->
    match String.get n 0 with
    | '0' | '1' | '2' | '3' | '4' | '5' |'6' |'7' | '8'| '9' -> "NN" ^ n
    | _ -> n
    )

let c_type_name er = Gobject_model.(Option.value ~default:er.name er.glibTypeName)

let make_c_func_name namespace class_name func_name = Format.sprintf "ml_%s_%s_%s" namespace class_name func_name

let ml_namespace namespace = CCString.mapi (fun i c ->
  match i with 
  | 0 -> CCChar.uppercase_ascii c
  | _ -> CCChar.lowercase_ascii c)
  namespace

let qualified_name context_namespace (ns, name) =
  if ns = context_namespace then name else (ns) ^ "." ^ name