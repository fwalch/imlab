#ifndef _HISTORY_H_
#define _HISTORY_H_

#include <string>
#include <vector>
#include <cstdint>
#include "store.h"
#include "../str_vector.h"

class History : public Store {
  public:
    std::vector<int32_t> h_c_id;
    std::vector<int32_t> h_c_d_id;
    std::vector<int32_t> h_c_w_id;
    std::vector<int32_t> h_d_id;
    std::vector<int32_t> h_w_id;
    std::vector<int64_t> h_date;
    std::vector<int64_t> h_amount;
    str_vector<24> h_data;
    void add(std::string[8]);
};

#endif
