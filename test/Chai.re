type assertion('a);

[@bs.module "chai"]
external expect: 'a => assertion('a) = "";
[@bs.send]
external toEqual: (assertion('a), 'a) => unit = "equal";
[@bs.send]
external equal: (assertion('a), 'a) => unit = "";
[@bs.get]
external t: assertion('a) => assertion('a) = "to";
[@bs.get]
external deep: assertion('a) => assertion('a) = "";
