#include <cstdlib>
#include <cstring>
#include "warehouse.h"
#include "conversion.h"

using namespace std;

void Warehouses::add(string elements[9]) {
  w_id.push_back(atoi(elements[0].c_str()));
  w_name.push_back(elements[1]);
  w_street_1.push_back(elements[2]);
  w_street_2.push_back(elements[3]);
  w_city.push_back(elements[4]);
  w_state.push_back(elements[5]);
  w_zip.push_back(elements[6]);
  w_tax.push_back(db_stol(elements[7]));
  w_ytd.push_back(db_stol(elements[8]));

  pkIndex[w_id[tid]] = tid;
  tid++;
}

uint64_t Warehouses::get(int32_t w_id) {
  return pkIndex[w_id];
}
