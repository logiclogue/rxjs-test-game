let canvas = Canvas.getById("canvas");
let ctx = canvas->Canvas.getContext("2d");

[@bs.send]
external forEach : (list('a), 'a => unit) => unit = "";

let entitiesStream = RxJS.createObservable(subscriber => {
    subscriber->RxJS.next([
        Player.create((0.0, 0.0)),
        Player.create((50.0, 0.0))
    ]);
    subscriber->RxJS.complete;
});

let loopStream = RxJS.interval(0, RxJS.animationFrame)->RxJS.share;

let draw = loopStream
    ->RxJS.withLatestFrom(entitiesStream)
    ->RxJS.subscribe(((loop, players)) => {
        ctx->Canvas.clearRect(0.0, 0.0, 100.0, 100.0);

        players->forEach(({ position: (x, y) }) => {
            ctx->Canvas.fillStyle("#FF0000");
            ctx->Canvas.fillRect(x, y, 10.0, 10.0);
        });
    });
