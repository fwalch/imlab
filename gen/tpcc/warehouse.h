#ifndef _TPCC_WAREHOUSE_H_
#define _TPCC_WAREHOUSE_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str_dictionary.h"
#include "schema.h"

namespace tpcc {

  class Warehouse : public Store {
    public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> w_id;
    std::vector<str::string> w_name;
    str::dictionary w_name_dict;
    std::vector<str::string> w_street_1;
    str::dictionary w_street_1_dict;
    std::vector<str::string> w_street_2;
    str::dictionary w_street_2_dict;
    std::vector<str::string> w_city;
    str::dictionary w_city_dict;
    std::vector<str::string> w_state;
    str::dictionary w_state_dict;
    std::vector<str::string> w_zip;
    str::dictionary w_zip_dict;
    std::vector<int64_t> w_tax;
    std::vector<int64_t> w_ytd;

    void add(std::string[9]);
    void add_instance(int32_t w_id, const char* w_name, const char* w_street_1, const char* w_street_2, const char* w_city, const char* w_state, const char* w_zip, int64_t w_tax, int64_t w_ytd);
    void remove(uint64_t tid);

    uint64_t get(int32_t w_id);
  };

}

#endif
