#ifndef _TPCC_DISTRICT_H_
#define _TPCC_DISTRICT_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str_dictionary.h"
#include "schema.h"

namespace tpcc {

  class District : public Store {
    public:
    typedef std::tuple<int32_t, int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> d_id;
    std::vector<int32_t> d_w_id;
    std::vector<str::string> d_name;
    str::dictionary d_name_dict;
    std::vector<str::string> d_street_1;
    str::dictionary d_street_1_dict;
    std::vector<str::string> d_street_2;
    str::dictionary d_street_2_dict;
    std::vector<str::string> d_city;
    str::dictionary d_city_dict;
    std::vector<str::string> d_state;
    str::dictionary d_state_dict;
    std::vector<str::string> d_zip;
    str::dictionary d_zip_dict;
    std::vector<int64_t> d_tax;
    std::vector<int64_t> d_ytd;
    std::vector<int32_t> d_next_o_id;

    void add(std::string[11]);
    void add_instance(int32_t d_id, int32_t d_w_id, const char* d_name, const char* d_street_1, const char* d_street_2, const char* d_city, const char* d_state, const char* d_zip, int64_t d_tax, int64_t d_ytd, int32_t d_next_o_id);
    void remove(uint64_t tid);

    uint64_t get(int32_t d_w_id, int32_t d_id);
  };

}

#endif
