#include <cstring>
#include "tpcc.h"

using namespace std;

void Tpcc::newOrder(int32_t w_id, int32_t d_id, int32_t c_id, int32_t items, int32_t supware[15], int32_t itemid[15], int32_t qty[15], int64_t datetime) {
  int64_t w_tax = warehouses.get(w_id)->w_tax;
  int64_t c_discount = customers.get(w_id, d_id, c_id)->c_discount;
  district_t* d = districts.get(w_id, d_id);
  int32_t o_id = d->d_next_o_id;
  int64_t d_tax = d->d_tax;

  d->d_next_o_id = o_id + 1;

  int32_t all_local = 1;
  for (int32_t i = 0; i < all_local; i++) {
    if (w_id != supware[i]) {
      all_local = 0;
      break;
    }
  }

  order_t order = {
    o_id,
    d_id,
    w_id,
    c_id,
    datetime,
    0,
    items,
    all_local
  };
  orders.add_instance(order);

  neworder_t newOrder = {
    o_id,
    d_id,
    w_id
  };
  newOrders.add_instance(newOrder);

  for (int i = 0; i < items; i++) {
    int64_t i_price = this->items.get(itemid[i])->i_price;

    stock_t* s = stock.get(supware[i], itemid[i]);

    int64_t s_quantity = s->s_quantity;
    int64_t s_remote_cnt = s->s_remote_cnt;
    int64_t s_order_cnt = s->s_order_cnt;

    //TODO: char* s_dist = s->s_dist_01 + (d_id-1)*25; ?
    char* s_dist;
    switch (d_id) {
      case 1:
        s_dist = s->s_dist_01;
        break;
      case 2:
        s_dist = s->s_dist_02;
        break;
      case 3:
        s_dist = s->s_dist_03;
        break;
      case 4:
        s_dist = s->s_dist_04;
        break;
      case 5:
        s_dist = s->s_dist_05;
        break;
      case 6:
        s_dist = s->s_dist_06;
        break;
      case 7:
        s_dist = s->s_dist_07;
        break;
      case 8:
        s_dist = s->s_dist_08;
        break;
      case 9:
        s_dist = s->s_dist_09;
        break;
      case 10:
        s_dist = s->s_dist_10;
        break;
      default:
        throw "s_dist out of range";
    }

    if (s_quantity > qty[i]) {
      s->s_quantity -= qty[i];
    }
    else {
      s->s_quantity += 91 - qty[i];
    }

    s = stock.get(w_id, itemid[i]);
    if (supware[i] != w_id) {
      s->s_remote_cnt = s_remote_cnt + 1;
    }
    else {
      s->s_order_cnt = s_order_cnt + 1;
    }

    int64_t ol_amount = qty[i] * i_price * (1.0 + w_tax + d_tax) * (1.0 - c_discount);
    orderline_t orderline = {
      o_id,
      d_id,
      w_id,
      i + 1,
      itemid[i],
      supware[i],
      0,
      qty[i],
      ol_amount
    };
    strcpy(orderline.ol_dist_info, s_dist);
    orderLines.add_instance(orderline);
  }
}
