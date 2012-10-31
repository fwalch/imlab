#include <cstdlib>
#include <climits>
#include "neworder.h"
#include "conversion.h"

using namespace std;

void NewOrders::add(string elements[3]) {
  add_instance(atoi(elements[0].c_str()),
    atoi(elements[1].c_str()),
    atoi(elements[2].c_str()));
}

void NewOrders::add_instance(int32_t no_o_id, int32_t no_d_id, int32_t no_w_id) {
  this->no_o_id.push_back(no_o_id);
  this->no_d_id.push_back(no_d_id);
  this->no_w_id.push_back(no_w_id);

  pkIndex[pkType(no_w_id, no_d_id, no_o_id)] = tid;
  tid++;
}

void NewOrders::remove(int32_t no_o_id, int32_t no_d_id, int32_t no_w_id) {
  auto indexElement = pkType(no_w_id, no_d_id, no_o_id);
  auto it = pkIndex.find(indexElement);
  uint64_t tid = it->second;
  pkIndex.erase(it);

  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->no_w_id[tid] = this->no_w_id[tidToSwap];
    this->no_d_id[tid] = this->no_d_id[tidToSwap];
    this->no_o_id[tid] = this->no_o_id[tidToSwap];

    // Set swapped item's TID in index
    pkIndex[pkType(this->no_w_id[tid], this->no_d_id[tid], this->no_o_id[tid])] = tid;
  }

  // Delete the data
  this->no_w_id.pop_back();
  this->no_d_id.pop_back();
  this->no_o_id.pop_back();
}

std::pair<NewOrders::pkIndexType::iterator, NewOrders::pkIndexType::iterator> NewOrders::get(int32_t no_w_id, int32_t no_d_id) {
  return std::make_pair(
    pkIndex.lower_bound(pkType(no_w_id, no_d_id, 0)),
    pkIndex.upper_bound(pkType(no_w_id, no_d_id, INT_MAX)));
}

uint64_t NewOrders::get(int32_t no_w_id, int32_t no_d_id, int32_t no_o_id) {
  return pkIndex[pkType(no_w_id, no_d_id, no_o_id)];
}
