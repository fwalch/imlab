#ifndef _STOCK_H_
#define _STOCK_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <cstdint>
#include "store.h"
#include "../str_vector.h"

class Stock : public Store {
  private:
    typedef std::tuple<int32_t, int32_t> pkIndexType;
    std::unordered_map<pkIndexType, uint64_t> pkIndex;

  public:
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
    uint64_t get(int32_t, int32_t);
};

#endif
