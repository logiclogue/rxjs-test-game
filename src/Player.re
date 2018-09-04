let create
: Entity.position => Entity.entity
= position => ({
    position: position,
    prevPosition: position,
    velocity: 0,
    direction: 0.0
});

let goNorth
: Entity.entity => Entity.entity
= player => ({
    ...player,
    velocity: 1,
    direction: 0.0
});

let goEast
: Entity.entity => Entity.entity
= player => {
    {
        ...player,
        velocity: 1,
        direction: Js_math._PI /. 4.0
    }
};

let goSouth
: Entity.entity => Entity.entity
= player => {
    {
        ...player,
        velocity: 1,
        direction: Js_math._PI /. 2.0
    }
};

let goWest
: Entity.entity => Entity.entity
= player => {
    {
        ...player,
        velocity: 1,
        direction: (3.0 *. Js_math._PI) /. 4.0
    }
};
