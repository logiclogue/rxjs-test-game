let canvas = Canvas.getById("canvas");
let ctx = canvas->Canvas.getContext("2d");

let entitiesStream = RxJS.createObservable(subscriber => {
    subscriber->RxJS.next(Player.create((0.0, 0.0)));
    subscriber->RxJS.next(Player.create((50.0, 0.0)));
    subscriber->RxJS.complete;
});

let loopStream = RxJS.interval(0, RxJS.animationFrame)->RxJS.share;

let draw = loopStream
    ->RxJS.withLatestFrom(entitiesStream)
    ->RxJS.subscribe(({ position: (x, y) }) => {
        ctx->Canvas.fillRect(x, y, 10.0, 10.0);
    });
