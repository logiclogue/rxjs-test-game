let loop_stream = RxJS.interval 0 RxJS.animation_frame
    |> RxJS.share ()

let player_modifier_stream = Keydown.key_code_stream
    |> RxJS.map (fun key_code -> Player.keycode_to_modifier key_code
        |> GameState.update_player)

let tick_modifier_stream = RxJS.set_interval 100
    |> RxJS.map_to GameState.tick

let reduce acc value _index = value acc

let game_state_stream = RxJS.merge [|
    player_modifier_stream;
    tick_modifier_stream;
|]
    |> RxJS.scan reduce GameState.default

let draw = RxJS.with_latest_from game_state_stream loop_stream
    |> RxJS.map snd
    |> RxJS.subscribe Renderer.render_game_state

let () = Keydown.key_code_stream
    |> RxJS.subscribe Js.log
