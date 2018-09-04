let canvas = Canvas.getById("canvas");
let ctx    = canvas->Canvas.getContext("2d");

let gameStateStream = RxJS.createObservable(subscriber => {
    subscriber->RxJS.next(GameState.{
        player: Player.create((10.0, 10.0)),
        entities: [
            Player.create((0.0, 0.0)),
            Player.create((50.0, 0.0))
        ]
    });
    subscriber->RxJS.complete;
});

let loopStream = RxJS.interval(0, RxJS.animationFrame)->RxJS.share;

let renderEntity
: Entity.entity => unit
= ({ position: (x, y) }) => {
    ctx->Canvas.fillStyle("#FF0000");
    ctx->Canvas.fillRect(x, y, 10.0, 10.0);
};

let renderPlayer
: Entity.entity => unit
= ({ position: (x, y) }) => {
    ctx->Canvas.fillStyle("#00FF00");
    ctx->Canvas.fillRect(x, y, 10.0, 10.0);
};

let renderGameState
: GameState.gameState => unit
= ({ player, entities }) => {
    ctx->Canvas.clearRect(0.0, 0.0, 100.0, 100.0);

    entities |> List.iter(renderEntity);

    renderPlayer(player);
};

let draw = loopStream
    ->RxJS.withLatestFrom(gameStateStream)
    ->RxJS.map(((_loop, gameState)) => gameState)
    ->RxJS.subscribe(renderGameState);
