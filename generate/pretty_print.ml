
let pp_comma ppf () = Format.fprintf ppf ", @ "
let pp_pipe ppf () = Format.fprintf ppf " | "
let pp_arrow ppf () = Format.fprintf ppf " -> "
let pp_string_pair ppf (x, y) = Format.fprintf ppf "(%s,%s)" x y