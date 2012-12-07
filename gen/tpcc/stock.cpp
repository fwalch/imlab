#include <climits>
#include <cstdlib>
#include <cstring>
#include "stock.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

void Stock::add(string elements[17]) {
  add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), db_stol(elements[2]), elements[3].c_str(), elements[4].c_str(), elements[5].c_str(), elements[6].c_str(), elements[7].c_str(), elements[8].c_str(), elements[9].c_str(), elements[10].c_str(), elements[11].c_str(), elements[12].c_str(), db_stol(elements[13]), db_stol(elements[14]), db_stol(elements[15]), elements[16].c_str());
}

void Stock::add_instance(int32_t s_i_id, int32_t s_w_id, int64_t s_quantity, const char* s_dist_01, const char* s_dist_02, const char* s_dist_03, const char* s_dist_04, const char* s_dist_05, const char* s_dist_06, const char* s_dist_07, const char* s_dist_08, const char* s_dist_09, const char* s_dist_10, int64_t s_ytd, int64_t s_order_cnt, int64_t s_remote_cnt, const char* s_data) {
  this->s_i_id.push_back(s_i_id);
this->s_w_id.push_back(s_w_id);
this->s_quantity.push_back(s_quantity);
auto s_dist_01_str = this->s_dist_01_dict.make_string(s_dist_01);
this->s_dist_01.push_back(s_dist_01_str);
auto s_dist_02_str = this->s_dist_02_dict.make_string(s_dist_02);
this->s_dist_02.push_back(s_dist_02_str);
auto s_dist_03_str = this->s_dist_03_dict.make_string(s_dist_03);
this->s_dist_03.push_back(s_dist_03_str);
auto s_dist_04_str = this->s_dist_04_dict.make_string(s_dist_04);
this->s_dist_04.push_back(s_dist_04_str);
auto s_dist_05_str = this->s_dist_05_dict.make_string(s_dist_05);
this->s_dist_05.push_back(s_dist_05_str);
auto s_dist_06_str = this->s_dist_06_dict.make_string(s_dist_06);
this->s_dist_06.push_back(s_dist_06_str);
auto s_dist_07_str = this->s_dist_07_dict.make_string(s_dist_07);
this->s_dist_07.push_back(s_dist_07_str);
auto s_dist_08_str = this->s_dist_08_dict.make_string(s_dist_08);
this->s_dist_08.push_back(s_dist_08_str);
auto s_dist_09_str = this->s_dist_09_dict.make_string(s_dist_09);
this->s_dist_09.push_back(s_dist_09_str);
auto s_dist_10_str = this->s_dist_10_dict.make_string(s_dist_10);
this->s_dist_10.push_back(s_dist_10_str);
this->s_ytd.push_back(s_ytd);
this->s_order_cnt.push_back(s_order_cnt);
this->s_remote_cnt.push_back(s_remote_cnt);
auto s_data_str = this->s_data_dict.make_string(s_data);
this->s_data.push_back(s_data_str);
  this->pkIndex[std::make_tuple(this->s_w_id[tid], this->s_i_id[tid])] = tid;
  tid++;
}

void Stock::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->s_w_id[tid], this->s_i_id[tid]);
auto pkIt = this->pkIndex.find(pkKey);
this->pkIndex.erase(pkIt);


  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->s_i_id[tid] = this->s_i_id[tidToSwap];
this->s_w_id[tid] = this->s_w_id[tidToSwap];
this->s_quantity[tid] = this->s_quantity[tidToSwap];
this->s_dist_01[tid] = this->s_dist_01[tidToSwap];
this->s_dist_02[tid] = this->s_dist_02[tidToSwap];
this->s_dist_03[tid] = this->s_dist_03[tidToSwap];
this->s_dist_04[tid] = this->s_dist_04[tidToSwap];
this->s_dist_05[tid] = this->s_dist_05[tidToSwap];
this->s_dist_06[tid] = this->s_dist_06[tidToSwap];
this->s_dist_07[tid] = this->s_dist_07[tidToSwap];
this->s_dist_08[tid] = this->s_dist_08[tidToSwap];
this->s_dist_09[tid] = this->s_dist_09[tidToSwap];
this->s_dist_10[tid] = this->s_dist_10[tidToSwap];
this->s_ytd[tid] = this->s_ytd[tidToSwap];
this->s_order_cnt[tid] = this->s_order_cnt[tidToSwap];
this->s_remote_cnt[tid] = this->s_remote_cnt[tidToSwap];
this->s_data[tid] = this->s_data[tidToSwap];

    // Set swapped item's TID in index
    this->pkIndex[std::make_tuple(this->s_w_id[tid], this->s_i_id[tid])] = tid;
  }

  // Delete the data
  this->s_i_id.pop_back();
this->s_w_id.pop_back();
this->s_quantity.pop_back();
auto s_dist_01_sid = this->s_dist_01.back();
this->s_dist_01_dict.remove(s_dist_01_sid);
this->s_dist_01.pop_back();
auto s_dist_02_sid = this->s_dist_02.back();
this->s_dist_02_dict.remove(s_dist_02_sid);
this->s_dist_02.pop_back();
auto s_dist_03_sid = this->s_dist_03.back();
this->s_dist_03_dict.remove(s_dist_03_sid);
this->s_dist_03.pop_back();
auto s_dist_04_sid = this->s_dist_04.back();
this->s_dist_04_dict.remove(s_dist_04_sid);
this->s_dist_04.pop_back();
auto s_dist_05_sid = this->s_dist_05.back();
this->s_dist_05_dict.remove(s_dist_05_sid);
this->s_dist_05.pop_back();
auto s_dist_06_sid = this->s_dist_06.back();
this->s_dist_06_dict.remove(s_dist_06_sid);
this->s_dist_06.pop_back();
auto s_dist_07_sid = this->s_dist_07.back();
this->s_dist_07_dict.remove(s_dist_07_sid);
this->s_dist_07.pop_back();
auto s_dist_08_sid = this->s_dist_08.back();
this->s_dist_08_dict.remove(s_dist_08_sid);
this->s_dist_08.pop_back();
auto s_dist_09_sid = this->s_dist_09.back();
this->s_dist_09_dict.remove(s_dist_09_sid);
this->s_dist_09.pop_back();
auto s_dist_10_sid = this->s_dist_10.back();
this->s_dist_10_dict.remove(s_dist_10_sid);
this->s_dist_10.pop_back();
this->s_ytd.pop_back();
this->s_order_cnt.pop_back();
this->s_remote_cnt.pop_back();
auto s_data_sid = this->s_data.back();
this->s_data_dict.remove(s_data_sid);
this->s_data.pop_back();
}

uint64_t Stock::get(int32_t s_w_id, int32_t s_i_id) {
return this->pkIndex[std::make_tuple(s_w_id, s_i_id)];
}

}
