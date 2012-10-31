#ifndef _OLTP_H_
#define _OLTP_H

#include <cstdint>
#include "tpcc.h"

const unsigned Warehouses = 5;
const unsigned Orders = 150000;

void newOrderRandom(int64_t, int32_t, Tpcc*);
void deliveryRandom(int64_t, int32_t, Tpcc*);
int32_t urand(int32_t, int32_t);

#endif
