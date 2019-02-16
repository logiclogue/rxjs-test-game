type t

val default : t

val update_player : (Player.t -> Player.t) -> t -> t
val tick          : t -> t
