#ifndef _HISTORY_H_
#define _HISTORY_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include "../src/str_vector.h"
#include "schema.h"

class HistoryStore : public Store {
  public:
    

    std::vector<int32_t> h_c_id;
    std::vector<int32_t> h_c_d_id;
    std::vector<int32_t> h_c_w_id;
    std::vector<int32_t> h_d_id;
    std::vector<int32_t> h_w_id;
    std::vector<uint64_t> h_date;
    std::vector<int64_t> h_amount;
    str_vector<24> h_data;

    void add(std::string[8]);
    void add_instance(int32_t, int32_t, int32_t, int32_t, int32_t, uint64_t, int64_t, std::string);
    void remove(uint64_t);

    
};

#endif
