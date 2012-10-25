#ifndef _ORDERLINE_H_
#define _ORDERLINE_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"

struct orderline_t {
  int32_t ol_o_id;
  int32_t ol_d_id;
  int32_t ol_w_id;
  int32_t ol_number;
  int32_t ol_i_id;
  int32_t ol_supply_w_id;
  int64_t ol_delivery_d;
  int64_t ol_quantity;
  int64_t ol_amount;
  char ol_dist_info[25];
};

class OrderLines : public StoreBase<orderline_t> {
  private:
    std::unordered_map<int32_t, std::unordered_map<int32_t, std::unordered_map<int32_t, std::unordered_map<int32_t, orderline_t*> > > > pkIndex;

  protected:
    void onNewItem(orderline_t*);

  public:
    void add(std::string[10]);
    orderline_t* get(int32_t, int32_t, int32_t, int32_t);
};

#endif
