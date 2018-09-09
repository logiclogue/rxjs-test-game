type keydown

let document = [%raw {| document |}]

external get_key_code : keydown -> int = "keyCode" [@@bs.get]

let keydown_stream
: keydown RxJS.observable
= RxJS.from_event document "keydown"
    |. RxJS.share

let key_code_stream = RxJS.map keydown_stream get_key_code

let filter_key_stream x = RxJS.filter key_code_stream ((==) x)

let leftStream  = filter_key_stream 37
let upStream    = filter_key_stream 38
let rightStream = filter_key_stream 39
let downStream  = filter_key_stream 40
