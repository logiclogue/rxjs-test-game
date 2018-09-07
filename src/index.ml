let canvas = Canvas.getById "canvas"
let ctx    = canvas |. Canvas.getContext "2d"

let gameStateStream = RxJS.createOf [|GameState.{
    player   = Player.create (10.0, 10.0);
    entities = [
        Player.create (0.0, 0.0);
        Player.create (50.0, 0.0);
    ];
}|]

let loopStream = RxJS.interval 0 RxJS.animationFrame |. RxJS.share

let renderEntity { Entity.position = (x, y) } =
    ctx |. Canvas.fillStyle "#FF0000";
    ctx |. Canvas.fillRect x y 10.0 10.0;
    ()

let renderPlayer { Entity.position = (x, y) } =
    ctx |. Canvas.fillStyle "#00FF00";
    ctx |. Canvas.fillRect x y 10.0 10.0;
    ()

let renderGameState { GameState.player; entities } =
    ctx |. Canvas.clearRect 0.0 0.0 100.0 100.0;
    entities |> List.iter renderEntity;
    renderPlayer player;
    ()

let draw = RxJS.withLatestFrom loopStream gameStateStream
    |. RxJS.map snd
    |. RxJS.subscribe renderGameState

let () = Keydown.keyCodeStream
    |. RxJS.subscribe Js.log
