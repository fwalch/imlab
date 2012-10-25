#include <cstdlib>
#include <cstring>
#include "stock.h"
#include "conversion.h"

using namespace std;

void Stock::add(string elements[17]) {
  stock_t stock;

  stock.s_i_id = atoi(elements[0].c_str());
  stock.s_w_id = atoi(elements[1].c_str());
  stock.s_quantity = db_stol(elements[2]);
  strcpy(stock.s_dist_01, elements[3].c_str());
  strcpy(stock.s_dist_02, elements[4].c_str());
  strcpy(stock.s_dist_03, elements[5].c_str());
  strcpy(stock.s_dist_04, elements[6].c_str());
  strcpy(stock.s_dist_05, elements[7].c_str());
  strcpy(stock.s_dist_06, elements[8].c_str());
  strcpy(stock.s_dist_07, elements[9].c_str());
  strcpy(stock.s_dist_08, elements[10].c_str());
  strcpy(stock.s_dist_09, elements[11].c_str());
  strcpy(stock.s_dist_10, elements[12].c_str());
  stock.s_ytd = db_stol(elements[13]);
  stock.s_order_cnt = db_stol(elements[14]);
  stock.s_remote_cnt = db_stol(elements[15]);
  strcpy(stock.s_data, elements[16].c_str());

  StoreBase::add_instance(stock);
}

void Stock::onNewItem(stock_t* item) {
  pkIndex[item->s_w_id][item->s_i_id] = item;
}

stock_t* Stock::get(int32_t s_w_id, int32_t s_i_id) {
 return pkIndex[s_w_id][s_i_id];
}
