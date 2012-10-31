#include <cstdlib>
#include <cstring>
#include "orderline.h"
#include "conversion.h"

using namespace std;

void OrderLines::add(string elements[10]) {
  add_instance(
    atoi(elements[0].c_str()),
    atoi(elements[1].c_str()),
    atoi(elements[2].c_str()),
    atoi(elements[3].c_str()),
    atoi(elements[4].c_str()),
    atoi(elements[5].c_str()),
    db_stod(elements[6].c_str()),
    db_stol(elements[7].c_str()),
    db_stol(elements[8].c_str()),
    elements[9].c_str());
}
void OrderLines::add_instance(int32_t ol_o_id, int32_t ol_d_id, int32_t ol_w_id, int32_t ol_number, int32_t ol_i_id, int32_t ol_supply_w_id, uint64_t ol_delivery_d, int64_t ol_quantity, int64_t ol_amount, const char ol_dist_info[24]) {
  this->ol_o_id.push_back(ol_o_id);
  this->ol_d_id.push_back(ol_d_id);
  this->ol_w_id.push_back(ol_w_id);
  this->ol_number.push_back(ol_number);
  this->ol_i_id.push_back(ol_i_id);
  this->ol_supply_w_id.push_back(ol_supply_w_id);
  this->ol_delivery_d.push_back(ol_delivery_d);
  this->ol_quantity.push_back(ol_quantity);
  this->ol_amount.push_back(ol_amount);
  this->ol_dist_info.push_back(ol_dist_info);

  pkIndex[pkIndexType(ol_w_id, ol_d_id, ol_o_id, ol_number)] = tid;
  tid++;
}

uint64_t OrderLines::get(int32_t ol_w_id, int32_t ol_d_id, int32_t ol_o_id, int32_t ol_number) {
  return pkIndex[pkIndexType(ol_w_id, ol_d_id, ol_o_id, ol_number)];
}
