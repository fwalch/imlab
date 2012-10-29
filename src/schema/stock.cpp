#include <cstdlib>
#include <cstring>
#include "stock.h"
#include "conversion.h"

using namespace std;

void Stock::add(string elements[17]) {
  s_i_id.push_back(atoi(elements[0].c_str()));
  s_w_id.push_back(atoi(elements[1].c_str()));
  s_quantity.push_back(db_stol(elements[2]));
  s_dist_01.push_back(elements[3]);
  s_dist_02.push_back(elements[4]);
  s_dist_03.push_back(elements[5]);
  s_dist_04.push_back(elements[6]);
  s_dist_05.push_back(elements[7]);
  s_dist_06.push_back(elements[8]);
  s_dist_07.push_back(elements[9]);
  s_dist_08.push_back(elements[10]);
  s_dist_09.push_back(elements[11]);
  s_dist_10.push_back(elements[12]);
  s_ytd.push_back(db_stol(elements[13]));
  s_order_cnt.push_back(db_stol(elements[14]));
  s_remote_cnt.push_back(db_stol(elements[15]));
  s_data.push_back(elements[16].c_str());

  pkIndex[pkIndexType(s_w_id[tid], s_i_id[tid])] = tid;
  tid++;
}

uint64_t Stock::get(int32_t s_w_id, int32_t s_i_id) {
 return pkIndex[pkIndexType(s_w_id, s_i_id)];
}
