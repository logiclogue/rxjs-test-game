let empty = []

let insert k v map = (k, v) :: map

let find_opt f xs =
    try
        Some (List.find f xs)
    with
    | Not_found -> None

let lookup k map = map
    |> find_opt (fun (k', v) -> k == k')
    |> function
        | Some (k, v) -> v
        | None        -> false
