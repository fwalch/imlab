#ifndef _TPCC_ORDERLINE_H_
#define _TPCC_ORDERLINE_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/dictionary.h"
#include "schema.h"

namespace tpcc {

  class Orderline : public Store {
    public:
    typedef std::tuple<int32_t, int32_t, int32_t, int32_t> pkKeyType;
    typedef std::map<pkKeyType, uint64_t> pkIndexType;
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
    std::vector<uint64_t> ol_dist_info;
    str::dictionary ol_dist_info_dict;

    void add(std::string[10]);
    void add_instance(int32_t ol_o_id, int32_t ol_d_id, int32_t ol_w_id, int32_t ol_number, int32_t ol_i_id, int32_t ol_supply_w_id, uint64_t ol_delivery_d, int64_t ol_quantity, int64_t ol_amount, const char* ol_dist_info);
    void remove(uint64_t tid);

    uint64_t get(int32_t ol_w_id, int32_t ol_d_id, int32_t ol_o_id, int32_t ol_number);
    std::pair<Orderline::pkIndexType::iterator, Orderline::pkIndexType::iterator> get(int32_t ol_w_id, int32_t ol_d_id, int32_t ol_o_id);
  };

}

#endif
