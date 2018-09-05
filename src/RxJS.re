type subscriber('a);
type observable('a);
type scheduler;
type operatorFunction('a, 'b) = observable('a) => observable('b);
type monoTypeOperatorFunction('a) = operatorFunction('a, 'a);

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

[@bs.val] [@bs.module "rxjs"]
external animationFrame : scheduler = "";

[@bs.val] [@bs.module "rxjs"]
external interval : (int, scheduler) => observable(int) = "";

[@bs.val] [@bs.splice] [@bs.module "rxjs"]
external createOf : array('a) => observable('a) = "of";

[@bs.val] [@bs.splice]
external combineLatest : array(observable('a)) => observable('a) = "";

[@bs.val] [@bs.module "rxjs"]
external fromEvent : ('a, string) => observable('b) = "";

[@bs.module "rxjs/operators"]
external map : ('a => 'b) => operatorFunction('a, 'b) = "map";

[@bs.module "rxjs/operators"]
external filter : ('a => bool) => monoTypeOperatorFunction('a) = "";

[@bs.module "rxjs/operators"]
external sample : observable('a) => monoTypeOperatorFunction('b) = "";

[@bs.module "rxjs/operators"]
external share : unit => monoTypeOperatorFunction('a) = "";

[@bs.module "rxjs/operators"]
external tap : ('a => 'b) => monoTypeOperatorFunction('a) = "";

[@bs.module "rxjs/operators"]
external withLatestFrom : observable('b) => operatorFunction('a, ('a, 'b)) = "";

let map = (observable, f) => map(f, observable);
let filter = (observable, f) => filter(f, observable);
let sample = (observable, notifier) => sample(notifier, observable);
let share = observable => share((), observable);
let tap = (observable, f) => tap(f, observable);
let withLatestFrom = (observable, project) => withLatestFrom(project, observable);
