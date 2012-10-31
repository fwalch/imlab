// Generated 2012-11-07 12:31:26 UTC

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include "../src/str_vector.h"
#include <unordered_map>
#include "schema.h"

class CustomerStore : public Store {
  public:
    typedef std::tuple<int32_t, int32_t, int32_t> pkKeyType;
typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
pkIndexType pkIndex;

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
    void add_instance(int32_t, int32_t, int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, uint64_t, std::string, int64_t, int64_t, int64_t, int64_t, int64_t, int64_t, std::string);
    void remove(uint64_t);

    uint64_t get(int32_t, int32_t, int32_t);
};

#endif
