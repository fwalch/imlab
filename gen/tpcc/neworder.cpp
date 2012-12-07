#include <climits>
#include <cstdlib>
#include <cstring>
#include "neworder.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

void Neworder::add(string elements[3]) {
  add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), atoi(elements[2].c_str()));
}

void Neworder::add_instance(int32_t no_o_id, int32_t no_d_id, int32_t no_w_id) {
  this->no_o_id.push_back(no_o_id);
this->no_d_id.push_back(no_d_id);
this->no_w_id.push_back(no_w_id);
  this->pkIndex[std::make_tuple(this->no_w_id[tid], this->no_d_id[tid], this->no_o_id[tid])] = tid;
  tid++;
}

void Neworder::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->no_w_id[tid], this->no_d_id[tid], this->no_o_id[tid]);
auto pkIt = this->pkIndex.find(pkKey);
this->pkIndex.erase(pkIt);


  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->no_o_id[tid] = this->no_o_id[tidToSwap];
this->no_d_id[tid] = this->no_d_id[tidToSwap];
this->no_w_id[tid] = this->no_w_id[tidToSwap];

    // Set swapped item's TID in index
    this->pkIndex[std::make_tuple(this->no_w_id[tid], this->no_d_id[tid], this->no_o_id[tid])] = tid;
  }

  // Delete the data
  this->no_o_id.pop_back();
this->no_d_id.pop_back();
this->no_w_id.pop_back();
}

uint64_t Neworder::get(int32_t no_w_id, int32_t no_d_id, int32_t no_o_id) {
return this->pkIndex[std::make_tuple(no_w_id, no_d_id, no_o_id)];
}

std::pair<Neworder::pkIndexType::iterator, Neworder::pkIndexType::iterator> Neworder::get(int32_t no_w_id, int32_t no_d_id) {
 return std::make_pair(
this->pkIndex.lower_bound(std::make_tuple(no_w_id, no_d_id, 0)),
this->pkIndex.upper_bound(std::make_tuple(no_w_id, no_d_id, INT_MAX)));
}

}
