#ifndef _TPCC_H_
#define _TPCC_H_

#include <string>
#include <cstdint>
#include "../gen/tpcc/schema.h"

/**
 * Controller class for TPC-C tables and transactions.
 */
class Tpcc {
  public:
    tpcc::Warehouse warehouses;
    tpcc::District districts;
    tpcc::Customer customers;
    tpcc::History history;
    tpcc::Neworder newOrders;
    tpcc::Order orders;
    tpcc::Orderline orderLines;
    tpcc::Item items;
    tpcc::Stock stock;

    void newOrder(int32_t w_id, int32_t d_id, int32_t c_id, int32_t items, int32_t supware[15], int32_t itemid[15], int32_t qty[15], uint64_t datetime);
    void delivery(int32_t w_id, int32_t o_carrier_id, uint64_t datetime);
};

#endif
