#ifndef _DISTRICT_H_
#define _DISTRICT_H_

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cstdint>
#include "store.h"
#include "../str_vector.h"

class Districts : public Store {
  private:
    typedef std::tuple<int32_t, int32_t> pkIndexType;
    std::map<pkIndexType, uint64_t> pkIndex;

  public:
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
    uint64_t get(int32_t, int32_t);
};

#endif
