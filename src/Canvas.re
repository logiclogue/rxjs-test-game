type canvas;
type context;

[@bs.send]
external get_context: (canvas, string) => context = "getContext";

[@bs.send]
external fill_rect: (context, float, float, float, float) => unit = "fillRect";

[@bs.send]
external clear_rect: (context, float, float, float, float) => unit = "clearRect";

[@bs.set]
external fill_style: (context, string) => unit = "fillStyle";

let get_by_id
: string => canvas
= [%bs.raw {| id => document.getElementById(id) |}];
