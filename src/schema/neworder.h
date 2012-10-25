#ifndef _NEWORDER_H_
#define _NEWORDER_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"

struct neworder_t {
  int32_t no_o_id;
  int32_t no_d_id;
  int32_t no_w_id;
};

class NewOrders : public StoreBase<neworder_t> {
  private:
    std::unordered_map<int32_t, std::unordered_map<int32_t, std::unordered_map<int32_t, neworder_t*> > > pkIndex;

  protected:
    void onNewItem(neworder_t*);

  public:
    void add(std::string[3]);
    neworder_t* get(int32_t, int32_t, int32_t);
};

#endif
