let canvas = Canvas.get_by_id "canvas"
let ctx    = canvas |. Canvas.get_context "2d"

let render_entity { Entity.position = (x, y) } =
    Canvas.fill_style ctx "#FF0000";
    Canvas.fill_rect ctx x y 10.0 10.0;
    ()

let render_player { Entity.position = (x, y) } =
    Canvas.fill_style ctx "#00FF00";
    Canvas.fill_rect ctx x y 10.0 10.0;
    ()

let render_game_state { GameState.player; entities } =
    Canvas.clear_rect ctx 0.0 0.0 100.0 100.0;
    List.iter render_entity entities;
    render_player player;
    ()
