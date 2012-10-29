#ifndef _ORDER_H_
#define _ORDER_H_

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cstdint>
#include "store.h"

class Orders : public Store {
  private:
    typedef std::tuple<int32_t, int32_t, int32_t> pkIndexType;
    std::map<pkIndexType, uint64_t> pkIndex;

  public:
    std::vector<int32_t> o_id;
    std::vector<int32_t> o_d_id;
    std::vector<int32_t> o_w_id;
    std::vector<int32_t> o_c_id;
    std::vector<int64_t> o_entry_d;
    std::vector<int32_t> o_carrier_id;
    std::vector<int64_t> o_ol_cnt;
    std::vector<int64_t> o_all_local;
    void add(std::string[8]);
    uint64_t get(int32_t, int32_t, int32_t);
    void add_instance(int32_t o_id, int32_t o_d_id, int32_t o_w_id, int32_t o_c_id, int64_t o_entry_d, int32_t o_carrier_id, int64_t o_ol_cnt, int64_t o_all_local);
};

#endif
