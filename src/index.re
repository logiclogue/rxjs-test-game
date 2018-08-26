RxJS.createObservable(subscriber => {
    subscriber->RxJS.next(5);
    subscriber->RxJS.complete;
})
    ->RxJS.map(x => x + 1)
    ->RxJS.subscribe(Js.log);
