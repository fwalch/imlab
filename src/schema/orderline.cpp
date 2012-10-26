#include <cstdlib>
#include <cstring>
#include "orderline.h"
#include "conversion.h"

using namespace std;

void OrderLines::add(string elements[10]) {
  orderline_t orderline;

  orderline.ol_o_id = atoi(elements[0].c_str());
  orderline.ol_d_id = atoi(elements[1].c_str());
  orderline.ol_w_id = atoi(elements[2].c_str());
  orderline.ol_number = atoi(elements[3].c_str());
  orderline.ol_i_id = atoi(elements[4].c_str());
  orderline.ol_supply_w_id = db_stod(elements[5].c_str());
  orderline.ol_delivery_d = db_stod(elements[6].c_str());
  orderline.ol_quantity = db_stol(elements[7].c_str());
  orderline.ol_amount = db_stol(elements[8].c_str());
  strcpy(orderline.ol_dist_info, elements[9].c_str());

  StoreBase::add_instance(orderline);
}

void OrderLines::onNewItem(orderline_t* item, uint64_t tid) {
  pkIndex[pkIndexType(item->ol_w_id, item->ol_d_id, item->ol_o_id, item->ol_number)] = tid;
}

orderline_t* OrderLines::get(int32_t ol_w_id, int32_t ol_d_id, int32_t ol_o_id, int32_t ol_number) {
  return &store[pkIndex[pkIndexType(ol_w_id, ol_d_id, ol_o_id, ol_number)]];
}
