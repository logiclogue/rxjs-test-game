type position = (float * float)

type entity = {
    position:     position;
    prevPosition: position;
    velocity:     float;
    direction:    float;
}

let tick { position = (x, y); velocity; direction } =
    let newX = x +. (Js_math.cos direction *. velocity) in
    let newY = y +. (Js_math.sin direction *. velocity) in

    {
        position     = (newX, newY);
        prevPosition = (x, y);
        velocity     = velocity;
        direction    = direction;
    }
