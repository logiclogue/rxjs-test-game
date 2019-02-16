type t = {
    player:   Entity.entity;
    entities: Entity.entity list;
}

let default = {
    player   = Player.create (10.0, 10.0);
    entities = [
        Player.create (0.0, 0.0);
        Player.create (50.0, 0.0);
    ];
}

let update_player f game_state = {
    game_state with
    player = f game_state.player
}

let tick game_state = {
    game_state with
    player = Entity.tick game_state.player;
}
