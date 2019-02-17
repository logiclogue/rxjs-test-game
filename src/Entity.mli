type t

val default      : t
val tick         : t -> t

val set_position : Position.t -> t -> t

val reduce       : action -> t -> t
