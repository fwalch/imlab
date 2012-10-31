// Generated 2012-11-07 12:31:26 UTC

#ifndef _NEWORDER_H_
#define _NEWORDER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "schema.h"

class NeworderStore : public Store {
  public:
    typedef std::tuple<int32_t, int32_t, int32_t> pkKeyType;
typedef std::map<pkKeyType, uint64_t> pkIndexType;
pkIndexType pkIndex;

    std::vector<int32_t> no_o_id;
std::vector<int32_t> no_d_id;
std::vector<int32_t> no_w_id;

    void add(std::string[3]);
    void add_instance(int32_t, int32_t, int32_t);
    void remove(uint64_t);

    uint64_t get(int32_t, int32_t, int32_t);
std::pair<pkIndexType::iterator, pkIndexType::iterator> get(int32_t, int32_t);
};

#endif
