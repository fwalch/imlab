#ifndef _NEWORDER_H_
#define _NEWORDER_H_

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cstdint>
#include "store.h"

struct neworder_t {
  int32_t no_o_id;
  int32_t no_d_id;
  int32_t no_w_id;
};

class NewOrders : public StoreBase<neworder_t> {
  private:
    typedef std::tuple<int32_t, int32_t, int32_t> pkIndexType;
    std::map<pkIndexType, uint64_t> pkIndex;

  protected:
    void onNewItem(neworder_t*, uint64_t);

  public:
    void add(std::string[3]);
    neworder_t* get(int32_t, int32_t, int32_t);
};

#endif
