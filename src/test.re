let result = RxJS.createObservable(subscriber => {
    subscriber->RxJS.next(5);
    subscriber->RxJS.complete;
})
    |>RxJS.map(x => x + 1);

result->RxJS.subscribe(Js.log);
