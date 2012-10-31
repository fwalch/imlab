#ifndef _CONVERSION_H_
#define _CONVERSION_H_

#include <cstdint>
#include <string>
#include <cstdlib>

/**
 * Converts a NUMERIC(x,y) string to int64_t.
 *
 * x = Total number of digits
 * y = Number of digits after decimal separator
 *
 * Converted value represents number w/o decimal separator,
 * e.g. NUMERIC(10,2): 12.3 -> 1230
 *
 * @TODO relies on correct number of decimal places in str
 */
int64_t db_stol(std::string str);

/**
 * Converts a TIMESTAMP string to uint64_t.
 *
 * Value represents seconds since 01.01.1970.
 */
uint64_t db_stod(std::string str);

#endif
