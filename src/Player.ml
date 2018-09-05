let create position = Entity.{
    position     = position;
    prevPosition = position;
    velocity     = 0.0;
    direction    = 0.0;
}

let goNorth player = Entity.{
    player with
    velocity  = 1.0;
    direction = 0.0;
}

let goEast player = Entity.{
    player with
    velocity  = 1.0;
    direction = Js_math._PI /. 4.0;
}

let goSouth player = Entity.{
    player with
    velocity  = 1.0;
    direction = Js_math._PI /. 2.0;
}

let goWest player = Entity.{
    player with
    velocity  = 1.0;
    direction = (3.0 *. Js_math._PI) /. 4.0;
}
