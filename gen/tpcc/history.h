#ifndef _TPCC_HISTORY_H_
#define _TPCC_HISTORY_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace tpcc {

  class History : public Store {
    public:

    std::vector<int32_t> h_c_id;
    std::vector<int32_t> h_c_d_id;
    std::vector<int32_t> h_c_w_id;
    std::vector<int32_t> h_d_id;
    std::vector<int32_t> h_w_id;
    std::vector<uint64_t> h_date;
    std::vector<int64_t> h_amount;
    str::vector<24> h_data;

    void add(std::string[8]);
    void add_instance(int32_t h_c_id, int32_t h_c_d_id, int32_t h_c_w_id, int32_t h_d_id, int32_t h_w_id, uint64_t h_date, int64_t h_amount, std::string h_data);
    void remove(uint64_t tid);


  };

}

#endif
