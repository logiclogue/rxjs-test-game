type subscriber('a);
type observable('a);
type operatorFunction('a, 'b) = observable('a) => observable('b);

[@bs.new] [@bs.module "rxjs"]
external createSubscriber : subscriber('a) = "Subscriber";
[@bs.send]
external next : (subscriber('a), 'a) => unit = "";
[@bs.send]
external complete : subscriber('a) => unit = "";
[@bs.new] [@bs.module "rxjs"]
external createObservable : (subscriber('a) => unit) => observable('a) = "Observable";
[@bs.send]
external subscribe : (observable('a), 'a => unit) => unit = "";
[@bs.module "rxjs/operators"]
external map : ('a => 'b) => operatorFunction('a, 'b) = "map";

let map = (observable, f) => map(f, observable);
