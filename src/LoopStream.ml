let loop_stream = RxJS.interval 0 RxJS.animation_frame
    |> RxJS.share ()
