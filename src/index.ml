let canvas = Canvas.get_by_id "canvas"
let ctx    = canvas |. Canvas.get_context "2d"

let game_state_seed = GameState.{
    player   = Player.create (10.0, 10.0);
    entities = [
        Player.create (0.0, 0.0);
        Player.create (50.0, 0.0);
    ];
}

let loop_stream = RxJS.interval 0 RxJS.animation_frame
    |> RxJS.share ()

let render_entity { Entity.position = (x, y) } =
    ctx |. Canvas.fill_style "#FF0000";
    ctx |. Canvas.fill_rect x y 10.0 10.0;
    ()

let render_player { Entity.position = (x, y) } =
    ctx |. Canvas.fill_style "#00FF00";
    ctx |. Canvas.fill_rect x y 10.0 10.0;
    ()

let render_game_state { GameState.player; entities } =
    ctx |. Canvas.clear_rect 0.0 0.0 100.0 100.0;
    entities |> List.iter render_entity;
    render_player player;
    ()

let player_modifier_stream = Keydown.up_stream
    |> RxJS.map_to (GameState.update_player Player.go_north)

let reduce acc value _index = value acc

let game_state_stream = RxJS.merge [|player_modifier_stream|]
    |> RxJS.scan reduce game_state_seed

let draw = RxJS.with_latest_from game_state_stream loop_stream
    |> RxJS.map snd
    |. RxJS.subscribe render_game_state

let () = Keydown.key_code_stream
    |. RxJS.subscribe Js.log
