# Changelog

## 2013-02-06

 * Reverted main to parallel query/transaction execution

## 2012-11-21

 * Implemented generation of SQL queries from query trees
   * Supports print, selection, table scan, cross product and hash join
   * Query trees are hardcoded into the code generator
   * See `CodeGenerator/lib/query/builtin` for the example queries
 * Split code generator in two parts:
   * Schema generation (`CodeGenerator/bin/generate from-schema`)
   * Query generation (`CodeGenerator/bin/generate from-query`)

## 2012-11-14

 * Implemented SQL query as C++ code (non-generated)
 * Execute query in parallel to NewOrder transactions
 * Enhanced code generator to support non-PK indexes

## 2012-11-07

 * Code generation from SQL schema file

### Performance

Unchanged from last week

## 2012-10-31

 * Use `std::vector`s/TIDs instead of `std::list`s/pointers
 * Use column store instead of row store
 * Use `std::tuple` for multi-key indexes instead of nested maps
 * Implemented delivery transaction:
   * NewOrder prefix lookup
   * NewOrder deletion
 * Corrected `uint64_t`/`int64_t` mix-ups and NewOrder `ol_amount` calculation.

### Performance

Declined; probably due to use of `std::vector`, column store (reallocations when adding new items)

 1. NewOrder: ~48.000 orders/sec
 1. Deliver: ~11.000 deliveries/sec

## 2012-10-24

Initial implementation using lists for data storage, nested `std::unsigned_map`s and pointers for index lookups and row stores.

### Performance

 1. NewOrder: ~130.000 orders/sec
