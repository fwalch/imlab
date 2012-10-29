#include <cstdlib>
#include <cstring>
#include "customer.h"
#include "conversion.h"

using namespace std;

void Customers::add(string elements[21]) {
  c_id.push_back(atoi(elements[0].c_str()));
  c_d_id.push_back(atoi(elements[1].c_str()));
  c_w_id.push_back(atoi(elements[2].c_str()));
  c_first.push_back(elements[3]);
  c_middle.push_back(elements[4]);
  c_last.push_back(elements[5]);
  c_street_1.push_back(elements[6]);
  c_street_2.push_back(elements[7]);
  c_city.push_back(elements[8]);
  c_state.push_back(elements[9]);
  c_zip.push_back(elements[10]);
  c_phone.push_back(elements[11]);
  c_since.push_back(db_stod(elements[12]));
  c_credit.push_back(elements[13].c_str());
  c_credit_lim.push_back(db_stol(elements[14]));
  c_discount.push_back(db_stol(elements[15]));
  c_balance.push_back(db_stol(elements[16]));
  c_ytd_paymenr.push_back(db_stol(elements[17]));
  c_payment_cnt.push_back(db_stol(elements[18]));
  c_delivery_cnt.push_back(db_stol(elements[19]));
  c_data.push_back(elements[20]);

  pkIndex[pkIndexType(c_w_id[tid], c_d_id[tid], c_id[tid])] = tid;
  tid++;
}

uint64_t Customers::get(int32_t c_w_id, int32_t c_d_id, int32_t c_id) {
  return pkIndex[pkIndexType(c_w_id, c_d_id, c_id)];
}
