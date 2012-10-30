#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"
#include "../str_vector.h"

class Warehouses : public Store {
  private:
    std::unordered_map<int32_t, uint64_t> pkIndex;

  public:
    std::vector<int32_t> w_id;
    str_vector<10> w_name;
    str_vector<20> w_street_1;
    str_vector<20> w_street_2;
    str_vector<20> w_city;
    str_vector<2> w_state;
    str_vector<9> w_zip;
    std::vector<uint64_t> w_tax;
    std::vector<uint64_t> w_ytd;
    void add(std::string[9]);
    uint64_t get(int32_t);
};

#endif
