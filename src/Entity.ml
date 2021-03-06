type t = {
    position:      Position.t;
    prev_position: Position.t;
    velocity:      float;
    direction:     float;
}

type action = t -> t

let dispatch f self = f self

let default = {
    position      = (0.0, 0.0);
    prev_position = (0.0, 0.0);
    velocity      = 0.0;
    direction     = 0.0;
}

let tick { position = (x, y); velocity; direction } =
    let newX = x +. (Js_math.cos direction *. velocity) in
    let newY = y +. (Js_math.sin direction *. velocity) in

    {
        position      = (newX, newY);
        prev_position = (x, y);
        velocity      = velocity;
        direction     = direction;
    }

let set_position position self =
    { self with position }

let set_velocity velocity self =
    { self with velocity }

let set_direction direction self =
    { self with direction }
