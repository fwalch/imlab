#include <cstdlib>
#include "neworder.h"
#include "conversion.h"

using namespace std;

void NewOrders::add(string elements[3]) {
  add_instance(atoi(elements[0].c_str()),
    atoi(elements[1].c_str()),
    atoi(elements[2].c_str()));
}

void NewOrders::add_instance(int32_t no_o_id, int32_t no_d_id, int32_t no_w_id) {
  this->no_o_id.push_back(no_o_id);
  this->no_d_id.push_back(no_d_id);
  this->no_w_id.push_back(no_w_id);

  pkIndex[pkIndexType(no_w_id, no_d_id, no_o_id)] = tid;
  tid++;
}

uint64_t NewOrders::get(int32_t no_w_id, int32_t no_d_id, int32_t no_o_id) {
  return pkIndex[pkIndexType(no_w_id, no_d_id, no_o_id)];
}
