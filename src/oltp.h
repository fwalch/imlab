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

void newOrderRandom(uint64_t, int32_t, Tpcc*);
void deliveryRandom(uint64_t, int32_t, Tpcc*);
int32_t urand(int32_t, int32_t);
const char* genName(int32_t id);
int64_t randomnumeric62(int64_t min, int64_t max);
int32_t urandexcept(int32_t min, int32_t max, int32_t v);
int32_t nurand(int32_t A, int32_t x, int32_t y);

#endif
