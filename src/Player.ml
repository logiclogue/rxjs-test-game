let create position = Entity.{
    position     = position;
    prevPosition = position;
    velocity     = 0.0;
    direction    = 0.0;
}

let go_north player = Entity.{
    player with
    velocity  = 1.0;
    direction = 0.0;
}

let go_east player = Entity.{
    player with
    velocity  = 1.0;
    direction = Js_math._PI /. 4.0;
}

let go_south player = Entity.{
    player with
    velocity  = 1.0;
    direction = Js_math._PI /. 2.0;
}

let go_west player = Entity.{
    player with
    velocity  = 1.0;
    direction = (3.0 *. Js_math._PI) /. 4.0;
}
