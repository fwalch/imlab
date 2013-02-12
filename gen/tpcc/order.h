#ifndef _TPCC_ORDER_H_
#define _TPCC_ORDER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/dictionary.h"
#include "schema.h"

namespace tpcc {

  class Order : public Store {
    public:
    typedef std::tuple<int32_t, int32_t, int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    typedef std::tuple<int32_t, int32_t, int32_t, int32_t> order_wdcKeyType;
    typedef std::multimap<order_wdcKeyType, uint64_t> order_wdcIndexType;
    order_wdcIndexType order_wdcIndex;
    typedef std::tuple<int32_t> o_c_idKeyType;
    typedef std::multimap<o_c_idKeyType, uint64_t> o_c_idIndexType;
    o_c_idIndexType o_c_idIndex;

    std::vector<int32_t> o_id;
    std::vector<int32_t> o_d_id;
    std::vector<int32_t> o_w_id;
    std::vector<int32_t> o_c_id;
    std::vector<uint64_t> o_entry_d;
    std::vector<int32_t> o_carrier_id;
    std::vector<int64_t> o_ol_cnt;
    std::vector<int64_t> o_all_local;

    void add(std::string[8]);
    void add_instance(int32_t o_id, int32_t o_d_id, int32_t o_w_id, int32_t o_c_id, uint64_t o_entry_d, int32_t o_carrier_id, int64_t o_ol_cnt, int64_t o_all_local);
    void remove(uint64_t tid);

    uint64_t get(int32_t o_w_id, int32_t o_d_id, int32_t o_id);
    std::pair<Order::order_wdcIndexType::iterator, Order::order_wdcIndexType::iterator> getByOrder_wdc(int32_t o_w_id, int32_t o_d_id, int32_t o_c_id, int32_t o_id);
    std::pair<Order::o_c_idIndexType::iterator, Order::o_c_idIndexType::iterator> getByO_c_id(int32_t o_c_id);
  };

}

#endif
