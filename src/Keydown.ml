let document = [%raw {| document |}]

type keydown

external getKeyCode : keydown -> int = "keyCode" [@@bs.get]

let keydownStream
: keydown RxJS.observable
= RxJS.fromEvent document "keydown"
