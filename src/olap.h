#ifndef _OLAP_H_
#define _OLAP_H_

#include <cstdint>
#include <string>
#include "tpcc.h"

/**
 * @file
 * Defines C++ translations of SQL queries.
 */

int64_t lastNameOrderSum(const std::string, Tpcc*);

#endif
