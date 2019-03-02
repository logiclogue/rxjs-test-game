type t
type action

val default      : t
val dispatch     : action -> t -> t

val tick          : action
val set_position  : Position.t -> action
val set_velocity  : float      -> action
val set_direction : float      -> action
