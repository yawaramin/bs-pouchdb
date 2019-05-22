module Adapter: {
  type t;

  let http: t;
  let idb: t;
  let leveldb: t;
  let memory: t;
};

module Document: {
  type t;
  let make: (~id: string, Js.Json.t) => t;
};

type putResponse = {. "ok": bool, "id": string, "rev": string};
type t;

[@bs.send] external destroy: t => Js.Promise.t({. "ok": bool}) = "";

let make: (
  ~adapter: Adapter.t=?,
  ~auth: {. "username": string, "password": string}=?,
  ~auto_compaction: bool=?,
  ~deterministic_revs: bool=?,
  ~revs_limit: int=?,
  ~skip_setup: bool=?,
  string,
) => t;

[@bs.send.pipe: t] external post: Js.Json.t => Js.Promise.t(putResponse) = "";
let put: (~force: bool=?, Document.t, t) => Js.Promise.t(putResponse);
