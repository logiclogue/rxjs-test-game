let canvas = Canvas.getById("canvas");
let ctx = canvas->Canvas.getContext("2d");

let entitiesStream = RxJS.createObservable(subscriber => {
    subscriber->RxJS.next(Player.create((0.0, 0.0)));
    subscriber->RxJS.next(Player.create((50.0, 0.0)));
    subscriber->RxJS.complete;
});

entitiesStream->RxJS.subscribe(({ position: (x, y) }) => {
    ctx->Canvas.fillRect(x, y, 10.0, 10.0);
});

RxJS.createObservable(subscriber => {
    subscriber->RxJS.next(5);
    subscriber->RxJS.complete;
})
    ->RxJS.map(x => x + 1)
    ->RxJS.subscribe(Js.log);
