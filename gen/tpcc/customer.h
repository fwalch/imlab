#ifndef _TPCC_CUSTOMER_H_
#define _TPCC_CUSTOMER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str_dictionary.h"
#include "schema.h"

namespace tpcc {

  class Customer : public Store {
    public:
    typedef std::tuple<int32_t, int32_t, int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    typedef std::tuple<int32_t, int32_t, str::string, str::string> customer_wdlKeyType;
    typedef std::multimap<customer_wdlKeyType, uint64_t> customer_wdlIndexType;
    customer_wdlIndexType customer_wdlIndex;
    typedef std::tuple<str::string> c_lastKeyType;
    typedef std::multimap<c_lastKeyType, uint64_t> c_lastIndexType;
    c_lastIndexType c_lastIndex;
    std::vector<int32_t> c_id;
    std::vector<int32_t> c_d_id;
    std::vector<int32_t> c_w_id;
    std::vector<str::string> c_first;
    str::dictionary c_first_dict;
    std::vector<str::string> c_middle;
    str::dictionary c_middle_dict;
    std::vector<str::string> c_last;
    str::dictionary c_last_dict;
    std::vector<str::string> c_street_1;
    str::dictionary c_street_1_dict;
    std::vector<str::string> c_street_2;
    str::dictionary c_street_2_dict;
    std::vector<str::string> c_city;
    str::dictionary c_city_dict;
    std::vector<str::string> c_state;
    str::dictionary c_state_dict;
    std::vector<str::string> c_zip;
    str::dictionary c_zip_dict;
    std::vector<str::string> c_phone;
    str::dictionary c_phone_dict;
    std::vector<uint64_t> c_since;
    std::vector<str::string> c_credit;
    str::dictionary c_credit_dict;
    std::vector<int64_t> c_credit_lim;
    std::vector<int64_t> c_discount;
    std::vector<int64_t> c_balance;
    std::vector<int64_t> c_ytd_paymenr;
    std::vector<int64_t> c_payment_cnt;
    std::vector<int64_t> c_delivery_cnt;
    std::vector<str::string> c_data;
    str::dictionary c_data_dict;

    void add(std::string[21]);
    void add_instance(int32_t c_id, int32_t c_d_id, int32_t c_w_id, const char* c_first, const char* c_middle, const char* c_last, const char* c_street_1, const char* c_street_2, const char* c_city, const char* c_state, const char* c_zip, const char* c_phone, uint64_t c_since, const char* c_credit, int64_t c_credit_lim, int64_t c_discount, int64_t c_balance, int64_t c_ytd_paymenr, int64_t c_payment_cnt, int64_t c_delivery_cnt, const char* c_data);
    void remove(uint64_t tid);

    uint64_t get(int32_t c_w_id, int32_t c_d_id, int32_t c_id);
    std::pair<Customer::customer_wdlIndexType::iterator, Customer::customer_wdlIndexType::iterator> getByCustomer_wdl(int32_t c_w_id, int32_t c_d_id, const char* c_last, const char* c_first);
    std::pair<Customer::c_lastIndexType::iterator, Customer::c_lastIndexType::iterator> getByC_last(const char* c_last);
  };

}

#endif