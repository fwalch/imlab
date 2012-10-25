#include <cstdlib>
#include "order.h"
#include "conversion.h"

using namespace std;

void Orders::add(string elements[8]) {
  order_t order;

  order.o_id = atoi(elements[0].c_str());
  order.o_d_id = atoi(elements[1].c_str());
  order.o_w_id = atoi(elements[2].c_str());
  order.o_c_id = atoi(elements[3].c_str());
  order.o_entry_d = db_stod(elements[4].c_str());
  order.o_carrier_id = atoi(elements[5].c_str());
  order.o_ol_cnt = db_stod(elements[6].c_str());
  order.o_all_local = db_stod(elements[7].c_str());

  StoreBase::add_instance(order);
}

void Orders::onNewItem(order_t* item) {
  pkIndex[item->o_w_id][item->o_d_id][item->o_id] = item;
}

order_t* Orders::get(int32_t o_w_id, int32_t o_d_id, int32_t o_id) {
  return pkIndex[o_w_id][o_d_id][o_id];
}
