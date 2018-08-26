type promise('a);
type sprite;

[@bs.module "scrixel-spritesheet"]
external spriteSheet : (int, int, string) => promise(array(sprite)) = "scrixelSpriteSheet";
[@bs.module "scrixel-map"]
external map : string => promise(array(array(int))) = "scrixelMap";
