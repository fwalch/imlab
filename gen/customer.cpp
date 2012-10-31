// Generated 2012-11-07 12:31:26 UTC

#include <climits>
#include <cstdlib>
#include <cstring>
#include "customer.h"
#include "../src/schema/conversion.h"

using namespace std;

void CustomerStore::add(string elements[21]) {
  add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), atoi(elements[2].c_str()), elements[3], elements[4], elements[5], elements[6], elements[7], elements[8], elements[9], elements[10], elements[11], db_stod(elements[12]), elements[13], db_stol(elements[14]), db_stol(elements[15]), db_stol(elements[16]), db_stol(elements[17]), db_stol(elements[18]), db_stol(elements[19]), elements[20]);
}

void CustomerStore::add_instance(int32_t c_id, int32_t c_d_id, int32_t c_w_id, std::string c_first, std::string c_middle, std::string c_last, std::string c_street_1, std::string c_street_2, std::string c_city, std::string c_state, std::string c_zip, std::string c_phone, uint64_t c_since, std::string c_credit, int64_t c_credit_lim, int64_t c_discount, int64_t c_balance, int64_t c_ytd_paymenr, int64_t c_payment_cnt, int64_t c_delivery_cnt, std::string c_data) {
  this->c_id.push_back(c_id);
this->c_d_id.push_back(c_d_id);
this->c_w_id.push_back(c_w_id);
this->c_first.push_back(c_first);
this->c_middle.push_back(c_middle);
this->c_last.push_back(c_last);
this->c_street_1.push_back(c_street_1);
this->c_street_2.push_back(c_street_2);
this->c_city.push_back(c_city);
this->c_state.push_back(c_state);
this->c_zip.push_back(c_zip);
this->c_phone.push_back(c_phone);
this->c_since.push_back(c_since);
this->c_credit.push_back(c_credit);
this->c_credit_lim.push_back(c_credit_lim);
this->c_discount.push_back(c_discount);
this->c_balance.push_back(c_balance);
this->c_ytd_paymenr.push_back(c_ytd_paymenr);
this->c_payment_cnt.push_back(c_payment_cnt);
this->c_delivery_cnt.push_back(c_delivery_cnt);
this->c_data.push_back(c_data);

  pkIndex[std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_id[tid])] = tid;
  tid++;
}

void CustomerStore::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_id[tid]);
auto pkIt = pkIndex.find(pkKey);
pkIndex.erase(pkIt);

  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->c_id[tid] = this->c_id[tidToSwap];
this->c_d_id[tid] = this->c_d_id[tidToSwap];
this->c_w_id[tid] = this->c_w_id[tidToSwap];
this->c_first.set(tid, this->c_first[tidToSwap]);
this->c_middle.set(tid, this->c_middle[tidToSwap]);
this->c_last.set(tid, this->c_last[tidToSwap]);
this->c_street_1.set(tid, this->c_street_1[tidToSwap]);
this->c_street_2.set(tid, this->c_street_2[tidToSwap]);
this->c_city.set(tid, this->c_city[tidToSwap]);
this->c_state.set(tid, this->c_state[tidToSwap]);
this->c_zip.set(tid, this->c_zip[tidToSwap]);
this->c_phone.set(tid, this->c_phone[tidToSwap]);
this->c_since[tid] = this->c_since[tidToSwap];
this->c_credit.set(tid, this->c_credit[tidToSwap]);
this->c_credit_lim[tid] = this->c_credit_lim[tidToSwap];
this->c_discount[tid] = this->c_discount[tidToSwap];
this->c_balance[tid] = this->c_balance[tidToSwap];
this->c_ytd_paymenr[tid] = this->c_ytd_paymenr[tidToSwap];
this->c_payment_cnt[tid] = this->c_payment_cnt[tidToSwap];
this->c_delivery_cnt[tid] = this->c_delivery_cnt[tidToSwap];
this->c_data.set(tid, this->c_data[tidToSwap]);

    // Set swapped item's TID in index
    pkIndex[std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_id[tid])] = tid;
  }

  // Delete the data
  this->c_id.pop_back();
this->c_d_id.pop_back();
this->c_w_id.pop_back();
this->c_first.pop_back();
this->c_middle.pop_back();
this->c_last.pop_back();
this->c_street_1.pop_back();
this->c_street_2.pop_back();
this->c_city.pop_back();
this->c_state.pop_back();
this->c_zip.pop_back();
this->c_phone.pop_back();
this->c_since.pop_back();
this->c_credit.pop_back();
this->c_credit_lim.pop_back();
this->c_discount.pop_back();
this->c_balance.pop_back();
this->c_ytd_paymenr.pop_back();
this->c_payment_cnt.pop_back();
this->c_delivery_cnt.pop_back();
this->c_data.pop_back();
}

    uint64_t CustomerStore::get(int32_t c_w_id, int32_t c_d_id, int32_t c_id) {
      return pkIndex[std::make_tuple(c_w_id, c_d_id, c_id)];
    }

