type position = (float, float);

type entity = {
    position: position,
    prevPosition: position,
    velocity: int,
    direction: float
};

let tick = entity => {
    {
        position: entity.position,
        prevPosition: entity.position,
        velocity: entity.velocity,
        direction: entity.direction
    }
};
