#include <cstring>
#include <cstdlib>
#include <iostream>
#include "district.h"
#include "conversion.h"

using namespace std;

void Districts::add(string elements[11]) {
  district_t district;
  district.d_id = atoi(elements[0].c_str());
  district.d_w_id = atoi(elements[1].c_str());
  strcpy(district.d_name, elements[2].c_str());
  strcpy(district.d_street_1, elements[3].c_str());
  strcpy(district.d_street_2, elements[4].c_str());
  strcpy(district.d_city, elements[5].c_str());
  strcpy(district.d_state, elements[6].c_str());
  strcpy(district.d_zip, elements[7].c_str());
  district.d_tax = db_stol(elements[8]);
  district.d_ytd = db_stol(elements[9]);
  district.d_next_o_id = atoi(elements[10].c_str());

  StoreBase::add_instance(district);
}

void Districts::onNewItem(district_t* item) {
  pkIndex[item->d_w_id][item->d_id] = item;
}

district_t* Districts::get(int32_t d_w_id, int32_t d_id) {
  return pkIndex[d_w_id][d_id];
}
