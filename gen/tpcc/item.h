#ifndef _TPCC_ITEM_H_
#define _TPCC_ITEM_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str_dictionary.h"
#include "schema.h"

namespace tpcc {

  class Item : public Store {
    public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> i_id;
    std::vector<int32_t> i_im_id;
    std::vector<str::string> i_name;
    str::dictionary i_name_dict;
    std::vector<int64_t> i_price;
    std::vector<str::string> i_data;
    str::dictionary i_data_dict;

    void add(std::string[5]);
    void add_instance(int32_t i_id, int32_t i_im_id, const char* i_name, int64_t i_price, const char* i_data);
    void remove(uint64_t tid);

    uint64_t get(int32_t i_id);
  };

}

#endif
