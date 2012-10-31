#ifndef _ORDERLINE_H_
#define _ORDERLINE_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <cstdint>
#include "store.h"
#include "../str_vector.h"

class OrderLines : public Store {
  private:
    typedef std::tuple<int32_t, int32_t, int32_t, int32_t> pkIndexType;
    std::unordered_map<pkIndexType, uint64_t> pkIndex;

  public:
    std::vector<int32_t> ol_o_id;
    std::vector<int32_t> ol_d_id;
    std::vector<int32_t> ol_w_id;
    std::vector<int32_t> ol_number;
    std::vector<int32_t> ol_i_id;
    std::vector<int32_t> ol_supply_w_id;
    std::vector<uint64_t> ol_delivery_d;
    std::vector<int64_t> ol_quantity;
    std::vector<int64_t> ol_amount;
    str_vector<24> ol_dist_info;
    void add(std::string[10]);
    void add_instance(int32_t ol_o_id, int32_t ol_d_id, int32_t ol_w_id, int32_t ol_number, int32_t ol_i_id, int32_t ol_supply_w_id, uint64_t ol_delivery_d, int64_t ol_quantity, int64_t ol_amount, const char ol_dist_info[24]);
    uint64_t get(int32_t, int32_t, int32_t, int32_t);
};

#endif
