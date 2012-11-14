#ifndef _ITEM_H_
#define _ITEM_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include "../src/str_vector.h"
#include <unordered_map>
#include "schema.h"

class ItemStore : public Store {
  public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;

    std::vector<int32_t> i_id;
    std::vector<int32_t> i_im_id;
    str_vector<24> i_name;
    std::vector<int64_t> i_price;
    str_vector<50> i_data;

    void add(std::string[5]);
    void add_instance(int32_t, int32_t, std::string, int64_t, std::string);
    void remove(uint64_t);

    uint64_t get(int32_t);
};

#endif
