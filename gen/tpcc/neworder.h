#ifndef _TPCC_NEWORDER_H_
#define _TPCC_NEWORDER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/dictionary.h"
#include "schema.h"

namespace tpcc {

  class Neworder : public Store {
    public:
    typedef std::tuple<int32_t, int32_t, int32_t> pkKeyType;
    typedef std::map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;

    std::vector<int32_t> no_o_id;
    std::vector<int32_t> no_d_id;
    std::vector<int32_t> no_w_id;

    void add(std::string[3]);
    void add_instance(int32_t no_o_id, int32_t no_d_id, int32_t no_w_id);
    void remove(uint64_t tid);

    uint64_t get(int32_t no_w_id, int32_t no_d_id, int32_t no_o_id);
    std::pair<Neworder::pkIndexType::iterator, Neworder::pkIndexType::iterator> get(int32_t no_w_id, int32_t no_d_id);
  };

}

#endif
