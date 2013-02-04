#include <iostream>
#include <unordered_set>
#include <cstring>
#include "tax_query.h"

namespace tpcc {

void taxQuery(Tpcc* tpcc) {
  for (uint64_t warehouses_tid = 0; warehouses_tid < tpcc->warehouses.count(); warehouses_tid++) {
    auto w_name = tpcc->warehouses.w_name[warehouses_tid];
    auto w_id = tpcc->warehouses.w_id[warehouses_tid];
    if (w_id == 1) {
      for (uint64_t districts_tid = 0; districts_tid < tpcc->districts.count(); districts_tid++) {
        auto d_name = tpcc->districts.d_name[districts_tid];
        auto d_tax = tpcc->districts.d_tax[districts_tid];
        auto d_w_id = tpcc->districts.d_w_id[districts_tid];
        if (w_id == d_w_id) {
          std::cout << w_name << "|" << d_name << "|" << d_tax << std::endl;
        }
      }
    }
  }
}

}
