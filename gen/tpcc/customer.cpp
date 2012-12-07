#include <climits>
#include <cstdlib>
#include <cstring>
#include "customer.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

void Customer::add(string elements[21]) {
  add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), atoi(elements[2].c_str()), elements[3].c_str(), elements[4].c_str(), elements[5].c_str(), elements[6].c_str(), elements[7].c_str(), elements[8].c_str(), elements[9].c_str(), elements[10].c_str(), elements[11].c_str(), db_stod(elements[12]), elements[13].c_str(), db_stol(elements[14]), db_stol(elements[15]), db_stol(elements[16]), db_stol(elements[17]), db_stol(elements[18]), db_stol(elements[19]), elements[20].c_str());
}

void Customer::add_instance(int32_t c_id, int32_t c_d_id, int32_t c_w_id, const char* c_first, const char* c_middle, const char* c_last, const char* c_street_1, const char* c_street_2, const char* c_city, const char* c_state, const char* c_zip, const char* c_phone, uint64_t c_since, const char* c_credit, int64_t c_credit_lim, int64_t c_discount, int64_t c_balance, int64_t c_ytd_paymenr, int64_t c_payment_cnt, int64_t c_delivery_cnt, const char* c_data) {
  this->c_id.push_back(c_id);
this->c_d_id.push_back(c_d_id);
this->c_w_id.push_back(c_w_id);
auto c_first_str = this->c_first_dict.make_string(c_first);
this->c_first.push_back(c_first_str);
auto c_middle_str = this->c_middle_dict.make_string(c_middle);
this->c_middle.push_back(c_middle_str);
auto c_last_str = this->c_last_dict.make_string(c_last);
this->c_last.push_back(c_last_str);
auto c_street_1_str = this->c_street_1_dict.make_string(c_street_1);
this->c_street_1.push_back(c_street_1_str);
auto c_street_2_str = this->c_street_2_dict.make_string(c_street_2);
this->c_street_2.push_back(c_street_2_str);
auto c_city_str = this->c_city_dict.make_string(c_city);
this->c_city.push_back(c_city_str);
auto c_state_str = this->c_state_dict.make_string(c_state);
this->c_state.push_back(c_state_str);
auto c_zip_str = this->c_zip_dict.make_string(c_zip);
this->c_zip.push_back(c_zip_str);
auto c_phone_str = this->c_phone_dict.make_string(c_phone);
this->c_phone.push_back(c_phone_str);
this->c_since.push_back(c_since);
auto c_credit_str = this->c_credit_dict.make_string(c_credit);
this->c_credit.push_back(c_credit_str);
this->c_credit_lim.push_back(c_credit_lim);
this->c_discount.push_back(c_discount);
this->c_balance.push_back(c_balance);
this->c_ytd_paymenr.push_back(c_ytd_paymenr);
this->c_payment_cnt.push_back(c_payment_cnt);
this->c_delivery_cnt.push_back(c_delivery_cnt);
auto c_data_str = this->c_data_dict.make_string(c_data);
this->c_data.push_back(c_data_str);
  this->pkIndex[std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_id[tid])] = tid;
this->customer_wdlIndex.insert(std::make_pair(std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_last[tid], this->c_first[tid]), tid));
this->c_lastIndex.insert(std::make_pair(std::make_tuple(this->c_last[tid]), tid));
  tid++;
}

void Customer::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_id[tid]);
auto pkIt = this->pkIndex.find(pkKey);
this->pkIndex.erase(pkIt);


auto customer_wdlKey = std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_last[tid], this->c_first[tid]);
auto customer_wdlIt = this->customer_wdlIndex.find(customer_wdlKey);
this->customer_wdlIndex.erase(customer_wdlIt);


auto c_lastKey = std::make_tuple(this->c_last[tid]);
auto c_lastIt = this->c_lastIndex.find(c_lastKey);
this->c_lastIndex.erase(c_lastIt);


  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->c_id[tid] = this->c_id[tidToSwap];
this->c_d_id[tid] = this->c_d_id[tidToSwap];
this->c_w_id[tid] = this->c_w_id[tidToSwap];
this->c_first[tid] = this->c_first[tidToSwap];
this->c_middle[tid] = this->c_middle[tidToSwap];
this->c_last[tid] = this->c_last[tidToSwap];
this->c_street_1[tid] = this->c_street_1[tidToSwap];
this->c_street_2[tid] = this->c_street_2[tidToSwap];
this->c_city[tid] = this->c_city[tidToSwap];
this->c_state[tid] = this->c_state[tidToSwap];
this->c_zip[tid] = this->c_zip[tidToSwap];
this->c_phone[tid] = this->c_phone[tidToSwap];
this->c_since[tid] = this->c_since[tidToSwap];
this->c_credit[tid] = this->c_credit[tidToSwap];
this->c_credit_lim[tid] = this->c_credit_lim[tidToSwap];
this->c_discount[tid] = this->c_discount[tidToSwap];
this->c_balance[tid] = this->c_balance[tidToSwap];
this->c_ytd_paymenr[tid] = this->c_ytd_paymenr[tidToSwap];
this->c_payment_cnt[tid] = this->c_payment_cnt[tidToSwap];
this->c_delivery_cnt[tid] = this->c_delivery_cnt[tidToSwap];
this->c_data[tid] = this->c_data[tidToSwap];

    // Set swapped item's TID in index
    this->pkIndex[std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_id[tid])] = tid;
this->customer_wdlIndex.insert(std::make_pair(std::make_tuple(this->c_w_id[tid], this->c_d_id[tid], this->c_last[tid], this->c_first[tid]), tid));
this->c_lastIndex.insert(std::make_pair(std::make_tuple(this->c_last[tid]), tid));
  }

  // Delete the data
  this->c_id.pop_back();
this->c_d_id.pop_back();
this->c_w_id.pop_back();
auto c_first_sid = this->c_first.back();
this->c_first_dict.remove(c_first_sid);
this->c_first.pop_back();
auto c_middle_sid = this->c_middle.back();
this->c_middle_dict.remove(c_middle_sid);
this->c_middle.pop_back();
auto c_last_sid = this->c_last.back();
this->c_last_dict.remove(c_last_sid);
this->c_last.pop_back();
auto c_street_1_sid = this->c_street_1.back();
this->c_street_1_dict.remove(c_street_1_sid);
this->c_street_1.pop_back();
auto c_street_2_sid = this->c_street_2.back();
this->c_street_2_dict.remove(c_street_2_sid);
this->c_street_2.pop_back();
auto c_city_sid = this->c_city.back();
this->c_city_dict.remove(c_city_sid);
this->c_city.pop_back();
auto c_state_sid = this->c_state.back();
this->c_state_dict.remove(c_state_sid);
this->c_state.pop_back();
auto c_zip_sid = this->c_zip.back();
this->c_zip_dict.remove(c_zip_sid);
this->c_zip.pop_back();
auto c_phone_sid = this->c_phone.back();
this->c_phone_dict.remove(c_phone_sid);
this->c_phone.pop_back();
this->c_since.pop_back();
auto c_credit_sid = this->c_credit.back();
this->c_credit_dict.remove(c_credit_sid);
this->c_credit.pop_back();
this->c_credit_lim.pop_back();
this->c_discount.pop_back();
this->c_balance.pop_back();
this->c_ytd_paymenr.pop_back();
this->c_payment_cnt.pop_back();
this->c_delivery_cnt.pop_back();
auto c_data_sid = this->c_data.back();
this->c_data_dict.remove(c_data_sid);
this->c_data.pop_back();
}

uint64_t Customer::get(int32_t c_w_id, int32_t c_d_id, int32_t c_id) {
return this->pkIndex[std::make_tuple(c_w_id, c_d_id, c_id)];
}

std::pair<Customer::customer_wdlIndexType::iterator, Customer::customer_wdlIndexType::iterator> Customer::getByCustomer_wdl(int32_t c_w_id, int32_t c_d_id, const char* c_last, const char* c_first) {
return std::make_pair(
this->customer_wdlIndex.lower_bound(std::make_tuple(c_w_id, c_d_id, this->c_last_dict.make_string(c_last), this->c_first_dict.make_string(c_first))),
this->customer_wdlIndex.upper_bound(std::make_tuple(c_w_id, c_d_id, this->c_last_dict.make_string(c_last), this->c_first_dict.make_string(c_first))));
}

std::pair<Customer::c_lastIndexType::iterator, Customer::c_lastIndexType::iterator> Customer::getByC_last(const char* c_last) {
return std::make_pair(
this->c_lastIndex.lower_bound(std::make_tuple(this->c_last_dict.make_string(c_last))),
this->c_lastIndex.upper_bound(std::make_tuple(this->c_last_dict.make_string(c_last))));
}

}
