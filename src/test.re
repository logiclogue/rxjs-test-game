type subscriber('a);
type observable('a);

[@bs.new] [@bs.module "rxjs"] external createSubscriber : subscriber('a) = "Subscriber";
[@bs.send] external next : (subscriber('a), 'a) => unit = "";
[@bs.send] external complete : subscriber('a) => unit = "";
[@bs.new] [@bs.module "rxjs"] external createObservable : (subscriber('a) => unit) => observable('a) = "Observable";
[@bs.send] external subscribe : (observable('a), 'a => unit) => unit = "";

createObservable(subscriber => {
    subscriber->next("Jordan");
    subscriber->complete;
})
    ->subscribe(Js.log);
