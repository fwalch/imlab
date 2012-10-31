#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <cstdint>
#include "store.h"
#include "../str_vector.h"

class Customers : public Store {
  private:
    typedef std::tuple<int32_t, int32_t, int32_t> pkIndexType;
    std::unordered_map<pkIndexType, uint64_t> pkIndex;

  public:
    std::vector<int32_t> c_id;
    std::vector<int32_t> c_d_id;
    std::vector<int32_t> c_w_id;
    str_vector<16> c_first;
    str_vector<2> c_middle;
    str_vector<16> c_last;
    str_vector<20> c_street_1;
    str_vector<20> c_street_2;
    str_vector<20> c_city;
    str_vector<2> c_state;
    str_vector<9> c_zip;
    str_vector<16> c_phone;
    std::vector<uint64_t> c_since;
    str_vector<2> c_credit;
    std::vector<int64_t> c_credit_lim;
    std::vector<int64_t> c_discount;
    std::vector<int64_t> c_balance;
    std::vector<int64_t> c_ytd_paymenr;
    std::vector<int64_t> c_payment_cnt;
    std::vector<int64_t> c_delivery_cnt;
    str_vector<500> c_data;
    void add(std::string[21]);
    uint64_t get(int32_t, int32_t, int32_t);
};

#endif
