#include <cstdlib>
#include "neworder.h"
#include "conversion.h"

using namespace std;

void NewOrders::add(string elements[3]) {
  neworder_t neworder;

  neworder.no_o_id = atoi(elements[0].c_str());
  neworder.no_d_id = atoi(elements[1].c_str());
  neworder.no_w_id = atoi(elements[2].c_str());

  StoreBase::add_instance(neworder);
}

void NewOrders::onNewItem(neworder_t* item) {
  pkIndex[item->no_w_id][item->no_d_id][item->no_o_id] = item;
}

neworder_t* NewOrders::get(int32_t no_w_id, int32_t no_d_id, int32_t no_o_id) {
  return pkIndex[no_w_id][no_d_id][no_o_id];
}
