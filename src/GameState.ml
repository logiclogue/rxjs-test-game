type game_state = {
    player:   Entity.entity;
    entities: Entity.entity list;
}

let tick game_state = {
    game_state with
    player = Entity.tick game_state.player;
}
