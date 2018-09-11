type game_state = {
    player:   Entity.entity;
    entities: Entity.entity list;
}

let update_player f game_state = {
    game_state with
    player = f game_state.player
}

let tick game_state = {
    game_state with
    player = Entity.tick game_state.player;
}
