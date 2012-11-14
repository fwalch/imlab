#include <cstdint>
#include <string>
#include <cstdlib>
#include "oltp.h"

const char* genName(int32_t id) {
  std::string parts[10] = {
    "BAR",
    "OUGHT",
    "ABLE",
    "PRI",
    "PRES",
    "ESE",
    "ANTI",
    "CALLY",
    "ATION",
    "EING"
  };
  return (parts[(id/100)%10] + parts[(id/10)%10] + parts[id%10]).c_str();
}

int64_t randomnumeric62(int64_t min, int64_t max) {
  return min+(int64_t)(rand()%(int32_t)((max-min)*100)/100);
}

int32_t nurand(int32_t A, int32_t x, int32_t y) {
  return ((((rand()%A)|(rand()%(y-x+1)+x))+42)%(y-x+1))+x;
}

int32_t urand(int32_t min, int32_t max) {
  return (rand()%(max-min+1))+min;
}

int32_t urandexcept(int32_t min, int32_t max, int32_t v) {
  if (max <= min) {
    return min;
  }
  int32_t r = (rand()%(max-min))+min;
  return r >= v ? r+1 : r;
}

void newOrderRandom(uint64_t now, int32_t w_id, Tpcc* c)
{
  int32_t d_id = urand(1, 10);
  int32_t c_id = nurand(1023, 1, 3000);
  int32_t ol_cnt = urand(5, 15);

  int32_t supware[15];
  int32_t itemid[15];
  int32_t qty[15];

  for (int i = 0; i < ol_cnt; i++) {
    if (urand(1, 100) > 1) {
      supware[i] = w_id;
    }
    else {
      supware[i] = urandexcept(1, Warehouses, w_id);
    }
    itemid[i] = nurand(8191, 1, 100000);
    qty[i] = urand(1, 10);
  }
  for (int i = ol_cnt; i < 15; i++) {
     supware[i] = w_id;
  }

  c->newOrder(w_id, d_id, c_id, ol_cnt, supware, itemid, qty, now);
}

void deliveryRandom(uint64_t now, int32_t w_id, Tpcc* c) {
  int32_t carrier_id = urand(1, 10);
  c->delivery(w_id, carrier_id, now);
}

