let create position = Entity.{
    position     = position;
    prevPosition = position;
    velocity     = 0.0;
    direction    = 0.0;
}

let go_north player = Entity.{
    player with
    velocity  = 1.0;
    direction = Js.Math._PI +. (Js.Math._PI /. 2.0);
}

let go_east player = Entity.{
    player with
    velocity  = 1.0;
    direction = 0.0;
}

let go_south player = Entity.{
    player with
    velocity  = 1.0;
    direction = Js.Math._PI /. 2.0;
}

let go_west player = Entity.{
    player with
    velocity  = 1.0;
    direction = Js.Math._PI;
}

let keycode_to_modifier keycode =
    match keycode with
    | 37 -> go_west
    | 38 -> go_north
    | 39 -> go_east
    | 40 -> go_south
    | _  -> (fun player -> player)
