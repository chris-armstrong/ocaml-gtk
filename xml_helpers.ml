open Xmlm

let attr_opt name attrs =
    List.find_map
      (fun ((_, local), value) ->
        if String.equal local name then Some value else None)
      attrs

let attr name attrs = (attr_opt name attrs) |> Option.get

let expected_start_tag name s = Failure (Format.asprintf "Expected start tag \"%s\", got %a" name pp_signal s)
let expected_end_tag name s = Failure (Format.asprintf "Expected end tag \"%s\", got %a" name pp_signal s)

let tag name i =
  match peek i with
  | `El_start ((_, n), attrs) as s ->
      if n = name then (
        let s = input i in
        Format.printf "tag> start %s - %a\n" name pp_signal s;
        match input i with
        | `El_end -> attrs
        | s -> raise (expected_end_tag name s))
      else raise (expected_start_tag name s)
  | s -> raise (expected_start_tag name s)

let tag_opt name i =
  match peek i with
  | `El_start ((_, n), attrs) ->
      if n = name then (
        let s = input i in
        Format.printf "tag_opt> start %s - %a\n" name pp_signal s;
        let res = Some attrs in
        match input i with
        | `El_end -> res
        | s -> raise (expected_end_tag name s))
      else None
  | _ -> None

let block inner name i =
  match peek i with
  | `El_start ((_, n), attrs) as s ->
      Format.printf "block> start %s %a\n" name pp_signal s;
      if n = name then
        let _ = input i in
        let res = inner i ~attrs in
        match input i with
        | `El_end -> res
        | s -> raise (expected_end_tag name s)
      else raise (expected_start_tag name s)
  | s -> raise (expected_start_tag name s)

let block_opt inner name i =
  match peek i with
  | `El_start ((_, n), attrs) as s ->
      Format.printf "block_opt> start %s %a\n" name pp_signal s;
      if n = name then
        let _ = input i in
        let res = Some (inner i ~attrs) in
        match input i with
        | `El_end -> res
        | _ -> raise (expected_end_tag name s)
      else None
  | _ -> None

type ignoredTag = IgnoredTag

let rec ignore_block ?(level = -1) i =
  match input i with
  | `El_start ((_, _), _) -> ignore_block ~level:(level + 1) i
  | `El_end -> if level = 0 then IgnoredTag else ignore_block ~level:(level - 1) i
  | _ -> raise (Failure "Unbalanced when ignoring block")

let open_source filename ~(ns : string -> string option) =
  let in_chan = In_channel.open_bin filename in
  let source = `Channel in_chan in
  make_input ~ns ~strip:true source