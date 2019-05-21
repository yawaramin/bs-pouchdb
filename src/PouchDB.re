module Adapter = {
  type t = string;

  let idb = "idb";
  let leveldb = "leveldb";
  let http = "http";
};

type makeOptions;
type t;

[@bs.obj] external makeOptions: (
  ~name: string,
  ~auto_compaction: bool=?,
  ~adapter: Adapter.t=?,
  ~revs_limit: int=?,
  ~deterministic_revs: bool=?,
  unit,
) => makeOptions = "";

[@bs.new] external make: makeOptions => t = "PouchDB";

let make(
  ~adapter=?,
  ~auto_compaction=?,
  ~deterministic_revs=?,
  ~revs_limit=?,
  name,
) = make(makeOptions(
  ~name,
  ~auto_compaction?,
  ~adapter?,
  ~revs_limit?,
  ~deterministic_revs?,
  ()),
);
