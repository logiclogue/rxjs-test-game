let canvas = Canvas.get_by_id "canvas"
let ctx    = canvas |> Canvas.get_context "2d"

let render_entity { Entity.position = (x, y) } =
    ctx |> Canvas.fill_style "#FF0000";
    ctx |> Canvas.fill_rect x y 10.0 10.0;
    ()

let render_player { Entity.position = (x, y) } =
    ctx |> Canvas.fill_style "#00FF00";
    ctx |> Canvas.fill_rect x y 10.0 10.0;
    ()

let render_game_state { GameState.player; entities } =
    ctx |> Canvas.clear_rect 0.0 0.0 100.0 100.0;
    List.iter render_entity entities;
    render_player player;
    ()
