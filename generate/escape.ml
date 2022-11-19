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

let pascal_case_to_snake_case: (string -> string) = fun name ->
  name |> String.to_seq
  |> Seq.mapi (fun i c ->
         if i = 0 then ((Char.lowercase_ascii c) |> Char.escaped)
         else
           match c <= 'Z' with
           | true -> "_" ^ Char.escaped (Char.lowercase_ascii c)
           | false -> Char.escaped c)
  |> List.of_seq |> (String.concat "")

let ml_name er = Gobject_model.(er.name) |> pascal_case_to_snake_case |> escape_ml_keyword

let c_type_name er = Gobject_model.(Option.value ~default:er.name er.glibTypeName)