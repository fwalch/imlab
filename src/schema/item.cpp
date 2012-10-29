#include <cstdlib>
#include <cstring>
#include "item.h"
#include "conversion.h"

using namespace std;

void Items::add(string elements[5]) {
  i_id.push_back(atoi(elements[0].c_str()));
  i_im_id.push_back(atoi(elements[1].c_str()));
  i_name.push_back(elements[2]);
  i_price.push_back(db_stol(elements[3]));
  i_data.push_back(elements[4]);

  pkIndex[i_id[tid]] = tid;
  tid++;
}

uint64_t Items::get(int32_t i_id) {
  return pkIndex[i_id];
}
