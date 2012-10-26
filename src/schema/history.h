#ifndef _HISTORY_H_
#define _HISTORY_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"

struct history_t {
  int32_t h_c_id;
  int32_t h_c_d_id;
  int32_t h_c_w_id;
  int32_t h_d_id;
  int32_t h_w_id;
  int64_t h_date;
  int64_t h_amount;
  char h_data[25];
};

class History : public StoreBase<history_t> {
  protected:
    void onNewItem(history_t*, uint64_t);

  public:
    void add(std::string[8]);
};

#endif
