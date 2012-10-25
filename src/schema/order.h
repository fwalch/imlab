#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"

struct order_t {
  int32_t o_id;
  int32_t o_d_id;
  int32_t o_w_id;
  int32_t o_c_id;
  int64_t o_entry_d;
  int32_t o_carrier_id;
  int64_t o_ol_cnt;
  int64_t o_all_local;
};

class Orders : public StoreBase<order_t> {
  private:
    std::unordered_map<int32_t, std::unordered_map<int32_t, std::unordered_map<int32_t, order_t*> > > pkIndex;

  protected:
    void onNewItem(order_t*);

  public:
    void add(std::string[8]);
    order_t* get(int32_t, int32_t, int32_t);
};

#endif
