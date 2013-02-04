#ifndef _TPCC_WAREHOUSE_H_
#define _TPCC_WAREHOUSE_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace tpcc {

  class Warehouse : public Store {
    public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> w_id;
    str::vector<10> w_name;
    str::vector<20> w_street_1;
    str::vector<20> w_street_2;
    str::vector<20> w_city;
    str::vector<2> w_state;
    str::vector<9> w_zip;
    std::vector<int64_t> w_tax;
    std::vector<int64_t> w_ytd;

    void add(std::string[9]);
    void add_instance(int32_t w_id, std::string w_name, std::string w_street_1, std::string w_street_2, std::string w_city, std::string w_state, std::string w_zip, int64_t w_tax, int64_t w_ytd);
    void remove(uint64_t tid);

    uint64_t get(int32_t w_id);
  };

}

#endif
