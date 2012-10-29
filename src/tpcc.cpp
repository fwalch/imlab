#include <cstring>
#include "tpcc.h"

using namespace std;

void Tpcc::newOrder(int32_t w_id, int32_t d_id, int32_t c_id, int32_t items, int32_t supware[15], int32_t itemid[15], int32_t qty[15], int64_t datetime) {
  int64_t w_tax = warehouses.w_tax[warehouses.get(w_id)];
  int64_t c_discount = customers.c_discount[customers.get(w_id, d_id, c_id)];
  uint64_t d = districts.get(w_id, d_id);
  int32_t o_id = districts.d_next_o_id[d];
  int64_t d_tax = districts.d_tax[d];

  districts.d_next_o_id[d] = o_id + 1;

  int32_t all_local = 1;
  for (int32_t i = 0; i < all_local; i++) {
    if (w_id != supware[i]) {
      all_local = 0;
      break;
    }
  }

  orders.add_instance(
    o_id,
    d_id,
    w_id,
    c_id,
    datetime,
    0,
    items,
    all_local
  );

  newOrders.add_instance(
    o_id,
    d_id,
    w_id
  );

  for (int i = 0; i < items; i++) {
    int64_t i_price = this->items.i_price[this->items.get(itemid[i])];

    uint64_t s = stock.get(supware[i], itemid[i]);

    int64_t s_quantity = stock.s_quantity[s];
    int64_t s_remote_cnt = stock.s_remote_cnt[s];
    int64_t s_order_cnt = stock.s_order_cnt[s];

    char* s_dist;
    switch (d_id) {
      case 1:
        s_dist = stock.s_dist_01[s];
        break;
      case 2:
        s_dist = stock.s_dist_02[s];
        break;
      case 3:
        s_dist = stock.s_dist_03[s];
        break;
      case 4:
        s_dist = stock.s_dist_04[s];
        break;
      case 5:
        s_dist = stock.s_dist_05[s];
        break;
      case 6:
        s_dist = stock.s_dist_06[s];
        break;
      case 7:
        s_dist = stock.s_dist_07[s];
        break;
      case 8:
        s_dist = stock.s_dist_08[s];
        break;
      case 9:
        s_dist = stock.s_dist_09[s];
        break;
      case 10:
        s_dist = stock.s_dist_10[s];
        break;
      default:
        throw "s_dist out of range";
    }

    if (s_quantity > qty[i]) {
      stock.s_quantity[s] -= qty[i];
    }
    else {
      stock.s_quantity[s] += 91 - qty[i];
    }

    s = stock.get(w_id, itemid[i]);
    if (supware[i] != w_id) {
      stock.s_remote_cnt[s] = s_remote_cnt + 1;
    }
    else {
      stock.s_order_cnt[s] = s_order_cnt + 1;
    }

    int64_t ol_amount = qty[i] * i_price * (1.0 + w_tax + d_tax) * (1.0 - c_discount);
    orderLines.add_instance(
      o_id,
      d_id,
      w_id,
      i + 1,
      itemid[i],
      supware[i],
      0,
      qty[i],
      ol_amount,
      s_dist
    );
  }
}

void Tpcc::delivery(int32_t w_id, int32_t o_carrier_id, int64_t datetime) {
  for (int32_t d_id = 1; d_id <= 10; d_id++) {

  }
}
