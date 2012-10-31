#ifndef _OLTP_H_
#define _OLTP_H

#include <cstdint>
#include "tpcc.h"

/**
 * @file
 * Defines the C++ counterparts of oltp.script.
 */

/** Number of warehouses in the sample data */
const unsigned Warehouses = 5;

/** Number of orders in the sample data */
const unsigned Orders = 150000;

void newOrderRandom(int64_t, int32_t, Tpcc*);
void deliveryRandom(int64_t, int32_t, Tpcc*);
int32_t urand(int32_t, int32_t);

#endif
