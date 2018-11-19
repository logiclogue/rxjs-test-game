let empty = []

let insert k v map = (k, v) :: map

let lookup k map = map
    |> List.find (fun (k', v) -> k == k')
    |> (fun (k, v) -> v)
