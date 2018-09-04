type canvas;
type context;

[@bs.send]
external getContext: (canvas, string) => context = "";

[@bs.send]
external fillRect: (context, float, float, float, float) => unit = "";

[@bs.send]
external clearRect: (context, float, float, float, float) => unit = "";

[@bs.set]
external fillStyle: (context, string) => unit = "";

let getById
: string => canvas
= [%bs.raw {| id => document.getElementById(id) |}];
