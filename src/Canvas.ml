type canvas
type context

external get_context
    : canvas -> string -> context
    = "getContext"
    [@@bs.send]

let get_context
    : string -> canvas -> context
    = fun s self -> get_context self s

external fill_rect
    : context -> float -> float -> float -> float -> unit
    = "fillRect"
    [@@bs.send]

let fill_rect
    : float -> float -> float -> float -> context -> unit
    = fun x y w h self -> fill_rect self x y w h

external clear_rect
    : context -> float -> float -> float -> float -> unit
    = "clearRect"
    [@@bs.send]

let clear_rect
    : float -> float -> float -> float -> context -> unit
    = fun x y w h self -> clear_rect self x y w h

external fill_style
    : context -> string -> unit
    = "fillStyle"
    [@@bs.set]

let fill_style
    : string -> context -> unit
    = fun colour self -> fill_style self colour

let get_by_id
    : string -> canvas
    = [%bs.raw {| id => document.getElementById(id) |}];
