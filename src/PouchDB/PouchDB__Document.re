type t = Js.Json.t;

let make(~id, json) =
  Js.Obj.(empty()->assign(Obj.magic(json))->assign({"id": id}))->Obj.magic;
