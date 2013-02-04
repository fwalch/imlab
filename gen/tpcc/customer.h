#ifndef _TPCC_CUSTOMER_H_
#define _TPCC_CUSTOMER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace tpcc {

  class Customer : public Store {
    public:
    typedef std::tuple<int32_t, int32_t, int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    typedef std::tuple<int32_t, int32_t, std::string, std::string> customer_wdlKeyType;
    typedef std::multimap<customer_wdlKeyType, uint64_t> customer_wdlIndexType;
    customer_wdlIndexType customer_wdlIndex;
    typedef std::tuple<std::string> c_lastKeyType;
    typedef std::multimap<c_lastKeyType, uint64_t> c_lastIndexType;
    c_lastIndexType c_lastIndex;
    std::vector<int32_t> c_id;
    std::vector<int32_t> c_d_id;
    std::vector<int32_t> c_w_id;
    str::vector<16> c_first;
    str::vector<2> c_middle;
    str::vector<16> c_last;
    str::vector<20> c_street_1;
    str::vector<20> c_street_2;
    str::vector<20> c_city;
    str::vector<2> c_state;
    str::vector<9> c_zip;
    str::vector<16> c_phone;
    std::vector<uint64_t> c_since;
    str::vector<2> c_credit;
    std::vector<int64_t> c_credit_lim;
    std::vector<int64_t> c_discount;
    std::vector<int64_t> c_balance;
    std::vector<int64_t> c_ytd_paymenr;
    std::vector<int64_t> c_payment_cnt;
    std::vector<int64_t> c_delivery_cnt;
    str::vector<500> c_data;

    void add(std::string[21]);
    void add_instance(int32_t c_id, int32_t c_d_id, int32_t c_w_id, std::string c_first, std::string c_middle, std::string c_last, std::string c_street_1, std::string c_street_2, std::string c_city, std::string c_state, std::string c_zip, std::string c_phone, uint64_t c_since, std::string c_credit, int64_t c_credit_lim, int64_t c_discount, int64_t c_balance, int64_t c_ytd_paymenr, int64_t c_payment_cnt, int64_t c_delivery_cnt, std::string c_data);
    void remove(uint64_t tid);

    uint64_t get(int32_t c_w_id, int32_t c_d_id, int32_t c_id);
    std::pair<Customer::customer_wdlIndexType::iterator, Customer::customer_wdlIndexType::iterator> getByCustomer_wdl(int32_t c_w_id, int32_t c_d_id, std::string c_last, std::string c_first);
    std::pair<Customer::c_lastIndexType::iterator, Customer::c_lastIndexType::iterator> getByC_last(std::string c_last);
  };

}

#endif
