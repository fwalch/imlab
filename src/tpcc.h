#ifndef _TPCC_H_
#define _TPCC_H_

#include <string>
#include <cstdint>
#include "schema/schema.h"

class Tpcc {
  public:
    Warehouses warehouses;
    Districts districts;
    Customers customers;
    History history;
    NewOrders newOrders;
    Orders orders;
    OrderLines orderLines;
    Items items;
    Stock stock;

    void newOrder(int32_t w_id, int32_t d_id, int32_t c_id, int32_t items, int32_t supware[15], int32_t itemid[15], int32_t qty[15], int64_t datetime);
};

#endif
