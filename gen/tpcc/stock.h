#ifndef _TPCC_STOCK_H_
#define _TPCC_STOCK_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace tpcc {

  class Stock : public Store {
    public:
    typedef std::tuple<int32_t, int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> s_i_id;
    std::vector<int32_t> s_w_id;
    std::vector<int64_t> s_quantity;
    str::vector<24> s_dist_01;
    str::vector<24> s_dist_02;
    str::vector<24> s_dist_03;
    str::vector<24> s_dist_04;
    str::vector<24> s_dist_05;
    str::vector<24> s_dist_06;
    str::vector<24> s_dist_07;
    str::vector<24> s_dist_08;
    str::vector<24> s_dist_09;
    str::vector<24> s_dist_10;
    std::vector<int64_t> s_ytd;
    std::vector<int64_t> s_order_cnt;
    std::vector<int64_t> s_remote_cnt;
    str::vector<50> s_data;

    void add(std::string[17]);
    void add_instance(int32_t s_i_id, int32_t s_w_id, int64_t s_quantity, std::string s_dist_01, std::string s_dist_02, std::string s_dist_03, std::string s_dist_04, std::string s_dist_05, std::string s_dist_06, std::string s_dist_07, std::string s_dist_08, std::string s_dist_09, std::string s_dist_10, int64_t s_ytd, int64_t s_order_cnt, int64_t s_remote_cnt, std::string s_data);
    void remove(uint64_t tid);

    uint64_t get(int32_t s_w_id, int32_t s_i_id);
  };

}

#endif
