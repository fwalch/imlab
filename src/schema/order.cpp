#include <cstdlib>
#include "order.h"
#include "conversion.h"

using namespace std;

void Orders::add(string elements[8]) {
  add_instance(atoi(elements[0].c_str()),
    atoi(elements[1].c_str()),
    atoi(elements[2].c_str()),
    atoi(elements[3].c_str()),
    db_stod(elements[4].c_str()),
    atoi(elements[5].c_str()),
    db_stol(elements[6].c_str()),
    db_stol(elements[7].c_str()));
}

void Orders::add_instance(int32_t o_id, int32_t o_d_id, int32_t o_w_id, int32_t o_c_id, uint64_t o_entry_d, int32_t o_carrier_id, int64_t o_ol_cnt, int64_t o_all_local) {
  this->o_id.push_back(o_id);
  this->o_d_id.push_back(o_d_id);
  this->o_w_id.push_back(o_w_id);
  this->o_c_id.push_back(o_c_id);
  this->o_entry_d.push_back(o_entry_d);
  this->o_carrier_id.push_back(o_carrier_id);
  this->o_ol_cnt.push_back(o_ol_cnt);
  this->o_all_local.push_back(o_all_local);

  pkIndex[pkIndexType(o_w_id, o_d_id, o_id)] = tid;
  tid++;
}

uint64_t Orders::get(int32_t o_w_id, int32_t o_d_id, int32_t o_id) {
  return pkIndex[pkIndexType(o_w_id, o_d_id, o_id)];
}
