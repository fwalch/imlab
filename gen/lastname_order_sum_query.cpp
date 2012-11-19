#include <iostream>
#include <unordered_set>
#include <cstring>
#include "lastname_order_sum_query.h"

void lastnameOrderSumQuery(Tpcc* tpcc) {
  int64_t sum = 0;
  auto v_1 = std::unordered_set<std::tuple<int32_t, int32_t, int32_t>>();
  auto v_2 = std::unordered_set<std::tuple<int32_t>>();
  for (uint64_t customers_tid = 0; customers_tid < tpcc->customers.count(); customers_tid++) {
    auto c_id = tpcc->customers.c_id[customers_tid];
    auto c_last = tpcc->customers.c_last[customers_tid];
    if (strcmp(c_last, "BARBARBAR") == 0) {
      v_2.insert(std::make_tuple(c_id));
    }
  }
  
  for (uint64_t orders_tid = 0; orders_tid < tpcc->orders.count(); orders_tid++) {
    auto o_c_id = tpcc->orders.o_c_id[orders_tid];
    auto o_w_id = tpcc->orders.o_w_id[orders_tid];
    auto o_d_id = tpcc->orders.o_d_id[orders_tid];
    auto o_id = tpcc->orders.o_id[orders_tid];
    auto v_3 = v_2.find(std::make_tuple(o_c_id));
    if (v_3 != v_2.end()) {
      v_1.insert(std::make_tuple(o_w_id, o_d_id, o_id));
    }
  }
  
  
  for (uint64_t orderLines_tid = 0; orderLines_tid < tpcc->orderLines.count(); orderLines_tid++) {
    auto ol_w_id = tpcc->orderLines.ol_w_id[orderLines_tid];
    auto ol_d_id = tpcc->orderLines.ol_d_id[orderLines_tid];
    auto ol_o_id = tpcc->orderLines.ol_o_id[orderLines_tid];
    auto ol_amount = tpcc->orderLines.ol_amount[orderLines_tid];
    auto ol_quantity = tpcc->orderLines.ol_quantity[orderLines_tid];
    auto v_4 = v_1.find(std::make_tuple(ol_w_id, ol_d_id, ol_o_id));
    if (v_4 != v_1.end()) {
      sum += ol_quantity * ol_amount;
    }
  }
  
  
  std::cout << sum << std::endl;
}
