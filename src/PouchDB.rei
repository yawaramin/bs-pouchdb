module Adapter: {
  type t;

  let http: t;
  let idb: t;
  let leveldb: t;
};

type t;

let make: (
  ~adapter: Adapter.t=?,
  ~auto_compaction: bool=?,
  ~deterministic_revs: bool=?,
  ~revs_limit: int=?,
  string,
) => t;
