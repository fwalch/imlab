#include <cstring>
#include <climits>
#include "tpcc.h"

using namespace std;
using namespace tpcc;

void Tpcc::newOrder(int32_t w_id, int32_t d_id, int32_t c_id, int32_t items, int32_t supware[15], int32_t itemid[15], int32_t qty[15], uint64_t datetime) {
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

  for (int32_t i = 0; i < items; i++) {
    int64_t i_price = this->items.i_price[this->items.get(itemid[i])];

    uint64_t s = stock.get(supware[i], itemid[i]);

    int64_t s_quantity = stock.s_quantity[s];
    int64_t s_remote_cnt = stock.s_remote_cnt[s];
    int64_t s_order_cnt = stock.s_order_cnt[s];

    const char* s_dist;
    switch (d_id) {
      case 1:
        s_dist = stock.s_dist_01_dict.get(stock.s_dist_01[s]);
        break;
      case 2:
        s_dist = stock.s_dist_02_dict.get(stock.s_dist_02[s]);
        break;
      case 3:
        s_dist = stock.s_dist_03_dict.get(stock.s_dist_03[s]);
        break;
      case 4:
        s_dist = stock.s_dist_04_dict.get(stock.s_dist_04[s]);
        break;
      case 5:
        s_dist = stock.s_dist_05_dict.get(stock.s_dist_05[s]);
        break;
      case 6:
        s_dist = stock.s_dist_06_dict.get(stock.s_dist_06[s]);
        break;
      case 7:
        s_dist = stock.s_dist_07_dict.get(stock.s_dist_07[s]);
        break;
      case 8:
        s_dist = stock.s_dist_08_dict.get(stock.s_dist_08[s]);
        break;
      case 9:
        s_dist = stock.s_dist_09_dict.get(stock.s_dist_09[s]);
        break;
      case 10:
        s_dist = stock.s_dist_10_dict.get(stock.s_dist_10[s]);
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

    // NUMERIC(6,2)
    // w_tax, d_tax, c_discount: NUMERIC(4,4), 1.0 => 10000
    // i_price: NUMERIC(4,2), decimal separator shift by 2 places necessary
    int64_t ol_amount = qty[i] * i_price * ((10000 + w_tax + d_tax) * (10000 - c_discount) / 100);
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

void Tpcc::delivery(int32_t w_id, int32_t o_carrier_id, uint64_t datetime) {
  for (int32_t d_id = 1; d_id <= 10; d_id++) {
    auto neworder = newOrders.get(w_id, d_id);

    // Equal if no matching NewOrder was found
    if (neworder.first == neworder.second) {
      continue;
    }

    // Get MIN(no_o_id):
    //  * neworder.first is start iterator
    //    (== item with minimal no_o_id because
    //    of sorting within map)
    //  * iterator.first is index tuple
    //  * index tuple is no_w_id, no_d_id, no_o_id
    //    -> get last element (no_o_id)
    int32_t o_id = get<2>(neworder.first->first);

    uint64_t neworder_tid = newOrders.get(o_id, d_id, w_id);
    newOrders.remove(neworder_tid);
    uint64_t o = orders.get(w_id, d_id, o_id);
    int64_t o_ol_cnt = orders.o_ol_cnt[o];
    int32_t o_c_id = orders.o_c_id[o];

    orders.o_carrier_id[o] = o_carrier_id;

    // NUMERIC(6,2)
    int64_t ol_total = 0;
    for (int32_t ol_number = 1; ol_number <= o_ol_cnt; ol_number++) {
      uint64_t orderline = orderLines.get(w_id, d_id, o_id, ol_number);
      int64_t ol_amount = orderLines.ol_amount[orderline];
      // ol_amount is also NUMERIC(6,2), no shifting necessary
      ol_total += ol_amount;
      orderLines.ol_delivery_d[orderline] = datetime;
    }

    uint64_t customer = customers.get(w_id, d_id, o_c_id);
    customers.c_balance[customer] += ol_total;
  }
}
