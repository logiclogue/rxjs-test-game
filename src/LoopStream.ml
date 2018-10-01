let loop_stream = RxJS.interval 0 RxJS.animation_frame
    |> RxJS.share ()

let create state_stream = loop_stream
    |> RxJS.with_latest_from state_stream
    |> RxJS.map snd
    |> RxJS.share ()
