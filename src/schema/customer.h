#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cstdint>
#include "store.h"

struct customer_t {
  int32_t c_id;
  int32_t c_d_id;
  int32_t c_w_id;
  char c_first[17];
  char c_middle[3];
  char c_last[17];
  char c_street_1[21];
  char c_street_2[21];
  char c_city[21];
  char c_state[3];
  char c_zip[10];
  char c_phone[17];
  int64_t c_since;
  char c_credit[3];
  int64_t c_credit_lim;
  int64_t c_discount;
  int64_t c_balance;
  int64_t c_ytd_paymenr;
  int64_t c_payment_cnt;
  int64_t c_delivery_cnt;
  char c_data[501];
};

class Customers : public StoreBase<customer_t> {
  private:
    typedef std::tuple<int32_t, int32_t, int32_t> pkIndexType;
    std::map<pkIndexType, uint64_t> pkIndex;

  protected:
    void onNewItem(customer_t*, uint64_t);

  public:
    void add(std::string[21]);
    customer_t* get(int32_t, int32_t, int32_t);
};

#endif
