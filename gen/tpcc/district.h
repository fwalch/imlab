#ifndef _TPCC_DISTRICT_H_
#define _TPCC_DISTRICT_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace tpcc {

  class District : public Store {
    public:
    typedef std::tuple<int32_t, int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> d_id;
    std::vector<int32_t> d_w_id;
    str::vector<10> d_name;
    str::vector<20> d_street_1;
    str::vector<20> d_street_2;
    str::vector<20> d_city;
    str::vector<2> d_state;
    str::vector<9> d_zip;
    std::vector<int64_t> d_tax;
    std::vector<int64_t> d_ytd;
    std::vector<int32_t> d_next_o_id;

    void add(std::string[11]);
    void add_instance(int32_t d_id, int32_t d_w_id, std::string d_name, std::string d_street_1, std::string d_street_2, std::string d_city, std::string d_state, std::string d_zip, int64_t d_tax, int64_t d_ytd, int32_t d_next_o_id);
    void remove(uint64_t tid);

    uint64_t get(int32_t d_w_id, int32_t d_id);
  };

}

#endif
