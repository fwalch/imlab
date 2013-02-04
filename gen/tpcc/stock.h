#ifndef _TPCC_STOCK_H_
#define _TPCC_STOCK_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/dictionary.h"
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
    std::vector<uint64_t> s_dist_01;
    str::dictionary s_dist_01_dict;
    std::vector<uint64_t> s_dist_02;
    str::dictionary s_dist_02_dict;
    std::vector<uint64_t> s_dist_03;
    str::dictionary s_dist_03_dict;
    std::vector<uint64_t> s_dist_04;
    str::dictionary s_dist_04_dict;
    std::vector<uint64_t> s_dist_05;
    str::dictionary s_dist_05_dict;
    std::vector<uint64_t> s_dist_06;
    str::dictionary s_dist_06_dict;
    std::vector<uint64_t> s_dist_07;
    str::dictionary s_dist_07_dict;
    std::vector<uint64_t> s_dist_08;
    str::dictionary s_dist_08_dict;
    std::vector<uint64_t> s_dist_09;
    str::dictionary s_dist_09_dict;
    std::vector<uint64_t> s_dist_10;
    str::dictionary s_dist_10_dict;
    std::vector<int64_t> s_ytd;
    std::vector<int64_t> s_order_cnt;
    std::vector<int64_t> s_remote_cnt;
    std::vector<uint64_t> s_data;
    str::dictionary s_data_dict;

    void add(std::string[17]);
    void add_instance(int32_t s_i_id, int32_t s_w_id, int64_t s_quantity, const char* s_dist_01, const char* s_dist_02, const char* s_dist_03, const char* s_dist_04, const char* s_dist_05, const char* s_dist_06, const char* s_dist_07, const char* s_dist_08, const char* s_dist_09, const char* s_dist_10, int64_t s_ytd, int64_t s_order_cnt, int64_t s_remote_cnt, const char* s_data);
    void remove(uint64_t tid);

    uint64_t get(int32_t s_w_id, int32_t s_i_id);
  };

}

#endif
