# Changelog

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
