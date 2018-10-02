type key

let document = [%raw {| document |}]

external get_key_code : key -> int = "keyCode" [@@bs.get]

let event_stream event_name
    = RxJS.from_event document event_name |> RxJS.share ()

let keydown_stream : key RxJS.observable = event_stream "keydown"
let keyup_stream   : key RxJS.observable = event_stream "keyup"

let keydown_code_stream = RxJS.map get_key_code keydown_stream
let keyup_code_stream   = RxJS.map get_key_code keyup_stream
let filter_key_stream x = RxJS.filter ((==) x) keydown_code_stream

let left_stream  = filter_key_stream 37
let up_stream    = filter_key_stream 38
let right_stream = filter_key_stream 39
let down_stream  = filter_key_stream 40

let keydown_modifier = keydown_code_stream |> RxJS.map (fun key -> fun keys -> key :: keys)
