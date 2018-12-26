type app

external create
    : int -> int -> Js.Json.t -> app
    = "Application"
    [@@bs.new]
    [@@bs.module "pixi.js"]
