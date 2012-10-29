#include <cstring>
#include <cstdlib>
#include <iostream>
#include "conversion.h"
#include "district.h"

using namespace std;

void Districts::add(string elements[11]) {
  d_id.push_back(atoi(elements[0].c_str()));
  d_w_id.push_back(atoi(elements[1].c_str()));
  d_name.push_back(elements[2]);
  d_street_1.push_back(elements[3]);
  d_street_2.push_back(elements[4]);
  d_city.push_back(elements[5]);
  d_state.push_back(elements[6]);
  d_zip.push_back(elements[7]);
  d_tax.push_back(db_stol(elements[8]));
  d_ytd.push_back(db_stol(elements[9]));
  d_next_o_id.push_back(atoi(elements[10].c_str()));

  pkIndex[pkIndexType(d_w_id[tid], d_id[tid])] = tid;
  tid++;
}

uint64_t Districts::get(int32_t d_w_id, int32_t d_id) {
  return pkIndex[pkIndexType(d_w_id, d_id)];
}
