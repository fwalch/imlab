// Generated 2012-11-07 12:31:26 UTC

#ifndef _STOCK_H_
#define _STOCK_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include "../src/str_vector.h"
#include <unordered_map>
#include "schema.h"

class StockStore : public Store {
  public:
    typedef std::tuple<int32_t, int32_t> pkKeyType;
typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
pkIndexType pkIndex;

    std::vector<int32_t> s_i_id;
std::vector<int32_t> s_w_id;
std::vector<int64_t> s_quantity;
str_vector<24> s_dist_01;
str_vector<24> s_dist_02;
str_vector<24> s_dist_03;
str_vector<24> s_dist_04;
str_vector<24> s_dist_05;
str_vector<24> s_dist_06;
str_vector<24> s_dist_07;
str_vector<24> s_dist_08;
str_vector<24> s_dist_09;
str_vector<24> s_dist_10;
std::vector<int64_t> s_ytd;
std::vector<int64_t> s_order_cnt;
std::vector<int64_t> s_remote_cnt;
str_vector<50> s_data;

    void add(std::string[17]);
    void add_instance(int32_t, int32_t, int64_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, int64_t, int64_t, int64_t, std::string);
    void remove(uint64_t);

    uint64_t get(int32_t, int32_t);
};

#endif
