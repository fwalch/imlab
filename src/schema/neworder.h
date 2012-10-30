#ifndef _NEWORDER_H_
#define _NEWORDER_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <cstdint>
#include "store.h"

class NewOrders : public Store {
  private:
    typedef std::tuple<int32_t, int32_t, int32_t> pkIndexType;
    typedef std::unordered_map<pkIndexType, uint64_t> pkIndexMapType;
    pkIndexMapType pkIndex;

  public:
    std::vector<int32_t> no_o_id;
    std::vector<int32_t> no_d_id;
    std::vector<int32_t> no_w_id;
    void add(std::string[3]);
    void add_instance(int32_t no_o_id, int32_t no_d_id, int32_t no_w_id);
    uint64_t get(int32_t, int32_t, int32_t);
    std::pair<pkIndexMapType::iterator, pkIndexMapType::iterator> get(int32_t, int32_t);
    void remove(int32_t no_o_id, int32_t no_d_id, int32_t no_w_id);
};

#endif
