type 'a subscriber
type 'a observable
type scheduler

type ('a, 'b) operator_function = 'a observable -> 'b observable
type 'a mono_type_operator_function = 'a observable -> 'a observable

external create_subscriber
    : 'a subscriber
    = "Subscriber"
    [@@bs.new] [@@bs.module "rxjs"]

external next
    : 'a -> unit
    = ""
    [@@bs.send.pipe: 'a subscriber]

external complete
    : unit
    = ""
    [@@bs.send.pipe: 'a subscriber]

external create_observable
    : ('a subscriber -> unit) -> 'a observable
    = "Observable"
    [@@bs.new] [@@bs.module "rxjs"]

external subscribe
    : ('a -> unit) -> unit
    = ""
    [@@bs.send.pipe: 'a observable]

external animation_frame
    : scheduler
    = "animationFrame"
    [@@bs.val] [@@bs.module "rxjs"]

external interval
    : int -> scheduler -> int observable
    = ""
    [@@bs.val] [@@bs.module "rxjs"]

external create_of
    : 'a array -> 'a observable
    = "of"
    [@@bs.val] [@@bs.splice] [@@bs.module "rxjs"]

external combine_latest
    : ('a observable) array -> 'a observable
    = "combineLatest"
    [@@bs.val] [@@bs.splice]

external merge
    : ('a observable) array -> 'a observable
    = ""
    [@@bs.module "rxjs"] [@@bs.splice]

external from_event
    : 'a -> string -> 'b observable
    = "fromEvent"
    [@@bs.val] [@@bs.module "rxjs"]

external map
    : ('a -> 'b) -> ('a, 'b) operator_function
    = "map"
    [@@bs.module "rxjs/operators"]

external map_to
    : 'b -> ('a, 'b) operator_function
    = "mapTo"
    [@@bs.module "rxjs/operators"]

external merge_map
    : ('a -> 'b observable) -> ('a, 'b) operator_function
    = "mergeMap"
    [@@bs.module "rxjs/operators"]

external scan
    : ('b -> 'a -> int -> 'b) -> 'b -> ('a, 'b) operator_function
    = ""
    [@@bs.module "rxjs/operators"]

external filter
    : ('a -> bool) -> 'a mono_type_operator_function
    = ""
    [@@bs.module "rxjs/operators"]

external sample
    : 'a observable -> 'b mono_type_operator_function
    = ""
    [@@bs.module "rxjs/operators"]

external share
    : unit -> 'a mono_type_operator_function
    = ""
    [@@bs.module "rxjs/operators"]

external tap
    : ('a -> 'b) -> 'a mono_type_operator_function
    = ""
    [@@bs.module "rxjs/operators"]

external with_latest_from
    : 'b observable -> ('a, ('a * 'b)) operator_function
    = "withLatestFrom"
    [@@bs.module "rxjs/operators"]
