module Adapter = {
  type t = string;

  let idb = "idb";
  let leveldb = "leveldb";
  let http = "http";
  let memory = "memory";
};

type makeOptions;
type t;

[@bs.obj] external makeOptions: (
  ~name: string,
  ~auto_compaction: bool=?,
  ~adapter: Adapter.t=?,
  ~revs_limit: int=?,
  ~deterministic_revs: bool=?,
  ~auth: {. "username": string, "password": string}=?,
  ~skip_setup: bool=?,
  unit,
) => makeOptions = "";

[@bs.new] external make: makeOptions => t = "PouchDB";

let make(
  ~adapter=?,
  ~auth=?,
  ~auto_compaction=?,
  ~deterministic_revs=?,
  ~revs_limit=?,
  ~skip_setup=?,
  name,
) = make(makeOptions(
  ~name,
  ~auto_compaction?,
  ~adapter?,
  ~revs_limit?,
  ~deterministic_revs?,
  ~auth?,
  ~skip_setup?,
  ()),
);

[@bs.send] external destroy: t => Js.Promise.t({. "ok": bool}) = "";

module Document = PouchDB__Document;

type putResponse = {. "ok": bool, "id": string, "rev": string};

[@bs.send.pipe: t] external put: (
  Document.t,
  option({. "force": bool}),
) => Js.Promise.t(putResponse) = "";

let put(~force=?, document, db) = put(
  document,
  switch (force) {
  | Some(force) => Some({"force": force})
  | None => None
  },
  db,
);

[@bs.send.pipe: t] external post: Js.Json.t => Js.Promise.t(putResponse) = "";
