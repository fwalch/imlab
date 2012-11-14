#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include "../src/str_vector.h"
#include <unordered_map>
#include "schema.h"

class WarehouseStore : public Store {
  public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;

    std::vector<int32_t> w_id;
    str_vector<10> w_name;
    str_vector<20> w_street_1;
    str_vector<20> w_street_2;
    str_vector<20> w_city;
    str_vector<2> w_state;
    str_vector<9> w_zip;
    std::vector<int64_t> w_tax;
    std::vector<int64_t> w_ytd;

    void add(std::string[9]);
    void add_instance(int32_t, std::string, std::string, std::string, std::string, std::string, std::string, int64_t, int64_t);
    void remove(uint64_t);

    uint64_t get(int32_t);
};

#endif
