#include "olap.h"

int64_t lastNameOrderSum(const std::string lastName, Tpcc* tpcc) {
  int64_t sum = 0;

  // FROM customer WHERE c_last = ?
  auto c_range = tpcc->customers.getByC_last(lastName.c_str());
  for (auto c_it = c_range.first; c_it != c_range.second; c_it++) {
    uint64_t c_tid = c_it->second;

    auto c_id = tpcc->customers.c_id[c_tid];

    // FROM order WHERE o_c_id = c_id
    auto o_range = tpcc->orders.getByO_c_id(c_id);
    for (auto o_it = o_range.first; o_it != o_range.second; o_it++) {
      uint64_t o_tid = o_it->second;

      auto o_w_id = tpcc->orders.o_w_id[o_tid];
      auto o_d_id = tpcc->orders.o_d_id[o_tid];
      auto o_id = tpcc->orders.o_id[o_tid];

      // FROM orderline WHERE ol_w_id = o_w_id AND ol_d_id = o_d_id AND ol_o_id = o_id
      auto ol_range = tpcc->orderLines.get(o_w_id, o_d_id, o_id);
      for (auto ol_it = ol_range.first; ol_it != ol_range.second; ol_it++) {
        auto ol_tid = ol_it->second;

        auto ol_amount = tpcc->orderLines.ol_amount[ol_tid];
        auto ol_quantity = tpcc->orderLines.ol_quantity[ol_tid];

        sum += ol_amount * ol_quantity;
      }
    }
  }

  return sum;
}
