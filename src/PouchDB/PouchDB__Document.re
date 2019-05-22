type t = Js.Json.t;

let make(~id, json) =
  Js.Obj.(empty()->assign(Obj.magic(json))->assign({"_id": id}))->Obj.magic;
