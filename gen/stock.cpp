#include <climits>
#include <cstdlib>
#include <cstring>
#include "stock.h"
#include "../src/schema/conversion.h"

using namespace std;

void StockStore::add(string elements[17]) {
  add_instance(atoi(elements[0].c_str()),
    atoi(elements[1].c_str()),
    db_stol(elements[2]),
    elements[3],
    elements[4],
    elements[5],
    elements[6],
    elements[7],
    elements[8],
    elements[9],
    elements[10],
    elements[11],
    elements[12],
    db_stol(elements[13]),
    db_stol(elements[14]),
    db_stol(elements[15]),
    elements[16]);
}

void StockStore::add_instance(int32_t s_i_id, int32_t s_w_id, int64_t s_quantity, std::string s_dist_01, std::string s_dist_02, std::string s_dist_03, std::string s_dist_04, std::string s_dist_05, std::string s_dist_06, std::string s_dist_07, std::string s_dist_08, std::string s_dist_09, std::string s_dist_10, int64_t s_ytd, int64_t s_order_cnt, int64_t s_remote_cnt, std::string s_data) {
  this->s_i_id.push_back(s_i_id);
  this->s_w_id.push_back(s_w_id);
  this->s_quantity.push_back(s_quantity);
  this->s_dist_01.push_back(s_dist_01);
  this->s_dist_02.push_back(s_dist_02);
  this->s_dist_03.push_back(s_dist_03);
  this->s_dist_04.push_back(s_dist_04);
  this->s_dist_05.push_back(s_dist_05);
  this->s_dist_06.push_back(s_dist_06);
  this->s_dist_07.push_back(s_dist_07);
  this->s_dist_08.push_back(s_dist_08);
  this->s_dist_09.push_back(s_dist_09);
  this->s_dist_10.push_back(s_dist_10);
  this->s_ytd.push_back(s_ytd);
  this->s_order_cnt.push_back(s_order_cnt);
  this->s_remote_cnt.push_back(s_remote_cnt);
  this->s_data.push_back(s_data);

  pkIndex[std::make_tuple(this->s_w_id[tid], this->s_i_id[tid])] = tid;
  tid++;
}

void StockStore::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->s_w_id[tid], this->s_i_id[tid]);
  auto pkIt = pkIndex.find(pkKey);
  pkIndex.erase(pkIt);

  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->s_i_id[tid] = this->s_i_id[tidToSwap];
    this->s_w_id[tid] = this->s_w_id[tidToSwap];
    this->s_quantity[tid] = this->s_quantity[tidToSwap];
    this->s_dist_01.set(tid, this->s_dist_01[tidToSwap]);
    this->s_dist_02.set(tid, this->s_dist_02[tidToSwap]);
    this->s_dist_03.set(tid, this->s_dist_03[tidToSwap]);
    this->s_dist_04.set(tid, this->s_dist_04[tidToSwap]);
    this->s_dist_05.set(tid, this->s_dist_05[tidToSwap]);
    this->s_dist_06.set(tid, this->s_dist_06[tidToSwap]);
    this->s_dist_07.set(tid, this->s_dist_07[tidToSwap]);
    this->s_dist_08.set(tid, this->s_dist_08[tidToSwap]);
    this->s_dist_09.set(tid, this->s_dist_09[tidToSwap]);
    this->s_dist_10.set(tid, this->s_dist_10[tidToSwap]);
    this->s_ytd[tid] = this->s_ytd[tidToSwap];
    this->s_order_cnt[tid] = this->s_order_cnt[tidToSwap];
    this->s_remote_cnt[tid] = this->s_remote_cnt[tidToSwap];
    this->s_data.set(tid, this->s_data[tidToSwap]);

    // Set swapped item's TID in index
    pkIndex[std::make_tuple(this->s_w_id[tid], this->s_i_id[tid])] = tid;
  }

  // Delete the data
  this->s_i_id.pop_back();
  this->s_w_id.pop_back();
  this->s_quantity.pop_back();
  this->s_dist_01.pop_back();
  this->s_dist_02.pop_back();
  this->s_dist_03.pop_back();
  this->s_dist_04.pop_back();
  this->s_dist_05.pop_back();
  this->s_dist_06.pop_back();
  this->s_dist_07.pop_back();
  this->s_dist_08.pop_back();
  this->s_dist_09.pop_back();
  this->s_dist_10.pop_back();
  this->s_ytd.pop_back();
  this->s_order_cnt.pop_back();
  this->s_remote_cnt.pop_back();
  this->s_data.pop_back();
}

uint64_t StockStore::get(int32_t s_w_id, int32_t s_i_id) {
  return pkIndex[std::make_tuple(s_w_id, s_i_id)];
}

