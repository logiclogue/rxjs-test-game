let loop_stream = RxJS.interval 0 RxJS.animation_frame
    |> RxJS.share ()

let player_modifier_stream = Keydown.up_stream
    |> RxJS.map_to (GameState.update_player Player.go_north)

let tick_modifier_stream = RxJS.set_interval 100
    |> RxJS.map_to GameState.tick

let reduce acc value _index = value acc

let game_state_stream = RxJS.merge [|
    player_modifier_stream;
    tick_modifier_stream
|]
    |> RxJS.scan reduce GameState.default

let draw = RxJS.with_latest_from game_state_stream loop_stream
    |> RxJS.map snd
    |> RxJS.subscribe Renderer.render_game_state

let () = Keydown.key_code_stream
    |> RxJS.subscribe Js.log
