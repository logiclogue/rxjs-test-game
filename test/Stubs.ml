let still_entity = Entity.default
    |> Entity.dispatch (Entity.set_position (42.0, 0.0))

let forward_entity = Entity.default
    |> Entity.dispatch (Entity.set_position (42.0, 0.0))
    |> Entity.dispatch (Entity.set_velocity 1.0)

let right_entity = Entity.default
    |> Entity.dispatch (Entity.set_position (42.0, 0.0))
    |> Entity.dispatch (Entity.set_velocity 1.0)
    |> Entity.dispatch (Entity.set_direction (Js_math._PI /. 2.0))
