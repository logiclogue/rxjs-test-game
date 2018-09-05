let document = [%raw {| document |}]

type keydown

external getKeyCode : keydown -> int = "keyCode" [@@bs.get]

let keydownStream
: keydown RxJS.observable
= RxJS.fromEvent document "keydown"
    |. RxJS.share

let keyCodeStream = RxJS.map keydownStream getKeyCode

let filterKeyStream x = RxJS.filter keyCodeStream ((==) x)

let leftStream  = filterKeyStream 37
let upStream    = filterKeyStream 38
let rightStream = filterKeyStream 39
let downStream  = filterKeyStream 40
