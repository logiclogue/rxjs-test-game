type player = {
    position: Entity.position,
    prevPosition: Entity.position,
    velocity: int,
    direction: float
};

let create = position => ({
    position,
    prevPosition: position,
    velocity: 0,
    direction: 0.0
});

let goNorth = player => ({
    ...player,
    velocity: 1,
    direction: 0.0
});

let goEast = player => {
    {
        ...player,
        velocity: 1,
        direction: Js_math._PI /. 4.0
    }
};

let goSouth = player => {
    {
        ...player,
        velocity: 1,
        direction: Js_math._PI /. 2.0
    }
};

let goWest = player => {
    {
        ...player,
        velocity: 1,
        direction: (3.0 *. Js_math._PI) /. 4.0
    }
};
