// Generated 2012-11-07 12:31:26 UTC

#ifndef _ORDERLINE_H_
#define _ORDERLINE_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include "../src/str_vector.h"
#include <unordered_map>
#include "schema.h"

class OrderlineStore : public Store {
  public:
    typedef std::tuple<int32_t, int32_t, int32_t, int32_t> pkKeyType;
typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
pkIndexType pkIndex;

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
    void add_instance(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint64_t, int64_t, int64_t, std::string);
    void remove(uint64_t);

    uint64_t get(int32_t, int32_t, int32_t, int32_t);
};

#endif
