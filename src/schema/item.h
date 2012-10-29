#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include "store.h"
#include "../str_vector.h"

class Items : public Store {
  private:
    std::map<int32_t, uint64_t> pkIndex;

  public:
    std::vector<int32_t> i_id;
    std::vector<int32_t> i_im_id;
    str_vector<24> i_name;
    std::vector<int64_t> i_price;
    str_vector<50> i_data;
    void add(std::string[5]);
    uint64_t get(int32_t);
};

#endif
