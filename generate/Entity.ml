module EntityName = struct
  type t = string * string

  let compare (ns1, n1) (ns2, n2) =
    match String.compare ns1 ns2 with 0 -> String.compare n1 n2 | r -> r
end

module EntityMap = CCMap.Make (EntityName)

let map_entity_name binding_namespace entity_joined_name = match CCString.split_on_char '.' entity_joined_name with
  | [entity_ns; entity_name] -> (entity_ns, entity_name)
  | [entity_name] -> (binding_namespace, entity_name)
  | _ -> raise (Failure (Format.asprintf "Could not parse entity name: \"%s\"" entity_joined_name))