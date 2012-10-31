// Generated 2012-11-07 12:31:26 UTC

#ifndef _DISTRICT_H_
#define _DISTRICT_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include "../src/str_vector.h"
#include <unordered_map>
#include "schema.h"

class DistrictStore : public Store {
  public:
    typedef std::tuple<int32_t, int32_t> pkKeyType;
typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
pkIndexType pkIndex;

    std::vector<int32_t> d_id;
std::vector<int32_t> d_w_id;
str_vector<10> d_name;
str_vector<20> d_street_1;
str_vector<20> d_street_2;
str_vector<20> d_city;
str_vector<2> d_state;
str_vector<9> d_zip;
std::vector<int64_t> d_tax;
std::vector<int64_t> d_ytd;
std::vector<int32_t> d_next_o_id;

    void add(std::string[11]);
    void add_instance(int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, int64_t, int64_t, int32_t);
    void remove(uint64_t);

    uint64_t get(int32_t, int32_t);
};

#endif
