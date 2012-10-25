#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"

struct item_t {
  int32_t i_id;
  int32_t i_im_id;
  char i_name[25];
  int64_t i_price;
  char i_data[51];
};

class Items : public StoreBase<item_t> {
  private:
    std::unordered_map<int32_t, item_t*> pkIndex;

  protected:
    void onNewItem(item_t*);

  public:
    void add(std::string[5]);
    item_t* get(int32_t);
};

#endif
