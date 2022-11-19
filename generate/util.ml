module List = struct
  include Stdlib.List

  let map_results lr =
    List.fold_left
      (fun l i ->
        CCResult.flat_map (fun l -> CCResult.map (fun i -> i :: l) i) l)
      (Result.ok []) lr
end
