type t = {
    position:      Position.t;
    prev_position: Position.t;
    velocity:      float;
    direction:     float;
}

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
    {
        self with
        position;
    }
