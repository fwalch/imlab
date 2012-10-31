// Generated 2012-11-07 12:31:26 UTC

#ifndef _ORDER_H_
#define _ORDER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include "schema.h"

class OrderStore : public Store {
  public:
    typedef std::tuple<int32_t, int32_t, int32_t> pkKeyType;
typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
pkIndexType pkIndex;

    std::vector<int32_t> o_id;
std::vector<int32_t> o_d_id;
std::vector<int32_t> o_w_id;
std::vector<int32_t> o_c_id;
std::vector<uint64_t> o_entry_d;
std::vector<int32_t> o_carrier_id;
std::vector<int64_t> o_ol_cnt;
std::vector<int64_t> o_all_local;

    void add(std::string[8]);
    void add_instance(int32_t, int32_t, int32_t, int32_t, uint64_t, int32_t, int64_t, int64_t);
    void remove(uint64_t);

    uint64_t get(int32_t, int32_t, int32_t);
};

#endif
