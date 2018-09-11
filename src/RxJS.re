type subscriber('a);
type observable('a);
type scheduler;
type operator_function('a, 'b) = observable('a) => observable('b);
type mono_type_operator_function('a) = operator_function('a, 'a);

[@bs.new] [@bs.module "rxjs"]
external create_subscriber : subscriber('a) = "Subscriber";

[@bs.send]
external next : (subscriber('a), 'a) => unit = "";

[@bs.send]
external complete : subscriber('a) => unit = "";

[@bs.new] [@bs.module "rxjs"]
external create_observable : (subscriber('a) => unit) => observable('a) = "Observable";

[@bs.send]
external subscribe : (observable('a), 'a => unit) => unit = "";

[@bs.val] [@bs.module "rxjs"]
external animation_frame : scheduler = "animationFrame";

[@bs.val] [@bs.module "rxjs"]
external interval : (int, scheduler) => observable(int) = "";

[@bs.val] [@bs.splice] [@bs.module "rxjs"]
external create_of : array('a) => observable('a) = "of";

[@bs.val] [@bs.splice]
external combine_latest : array(observable('a)) => observable('a) = "combineLatest";

[@bs.val] [@bs.module "rxjs"]
external from_event : ('a, string) => observable('b) = "fromEvent";

[@bs.module "rxjs/operators"]
external map : ('a => 'b) => operator_function('a, 'b) = "map";

[@bs.module "rxjs/operators"]
external map_to : 'b => operator_function('a, 'b) = "mapTo";

[@bs.module "rxjs/operators"]
external scan : ((('b, 'a, int) => 'b), 'b) => operator_function('a, 'b) = "";

[@bs.module "rxjs/operators"]
external filter : ('a => bool) => mono_type_operator_function('a) = "";

[@bs.module "rxjs/operators"]
external sample : observable('a) => mono_type_operator_function('b) = "";

[@bs.module "rxjs/operators"]
external share : unit => mono_type_operator_function('a) = "";

[@bs.module "rxjs/operators"]
external tap : ('a => 'b) => mono_type_operator_function('a) = "";

[@bs.module "rxjs/operators"]
external with_latest_from : observable('b) => operator_function('a, ('a, 'b)) = "withLatestFrom";
