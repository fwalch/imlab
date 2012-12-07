#include <climits>
#include <cstdlib>
#include <cstring>
#include "order.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

void Order::add(string elements[8]) {
  add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), atoi(elements[2].c_str()), atoi(elements[3].c_str()), db_stod(elements[4]), atoi(elements[5].c_str()), db_stol(elements[6]), db_stol(elements[7]));
}

void Order::add_instance(int32_t o_id, int32_t o_d_id, int32_t o_w_id, int32_t o_c_id, uint64_t o_entry_d, int32_t o_carrier_id, int64_t o_ol_cnt, int64_t o_all_local) {
  this->o_id.push_back(o_id);
this->o_d_id.push_back(o_d_id);
this->o_w_id.push_back(o_w_id);
this->o_c_id.push_back(o_c_id);
this->o_entry_d.push_back(o_entry_d);
this->o_carrier_id.push_back(o_carrier_id);
this->o_ol_cnt.push_back(o_ol_cnt);
this->o_all_local.push_back(o_all_local);
  this->pkIndex[std::make_tuple(this->o_w_id[tid], this->o_d_id[tid], this->o_id[tid])] = tid;
this->order_wdcIndex.insert(std::make_pair(std::make_tuple(this->o_w_id[tid], this->o_d_id[tid], this->o_c_id[tid], this->o_id[tid]), tid));
this->o_c_idIndex.insert(std::make_pair(std::make_tuple(this->o_c_id[tid]), tid));
  tid++;
}

void Order::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->o_w_id[tid], this->o_d_id[tid], this->o_id[tid]);
auto pkIt = this->pkIndex.find(pkKey);
this->pkIndex.erase(pkIt);


auto order_wdcKey = std::make_tuple(this->o_w_id[tid], this->o_d_id[tid], this->o_c_id[tid], this->o_id[tid]);
auto order_wdcIt = this->order_wdcIndex.find(order_wdcKey);
this->order_wdcIndex.erase(order_wdcIt);


auto o_c_idKey = std::make_tuple(this->o_c_id[tid]);
auto o_c_idIt = this->o_c_idIndex.find(o_c_idKey);
this->o_c_idIndex.erase(o_c_idIt);


  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->o_id[tid] = this->o_id[tidToSwap];
this->o_d_id[tid] = this->o_d_id[tidToSwap];
this->o_w_id[tid] = this->o_w_id[tidToSwap];
this->o_c_id[tid] = this->o_c_id[tidToSwap];
this->o_entry_d[tid] = this->o_entry_d[tidToSwap];
this->o_carrier_id[tid] = this->o_carrier_id[tidToSwap];
this->o_ol_cnt[tid] = this->o_ol_cnt[tidToSwap];
this->o_all_local[tid] = this->o_all_local[tidToSwap];

    // Set swapped item's TID in index
    this->pkIndex[std::make_tuple(this->o_w_id[tid], this->o_d_id[tid], this->o_id[tid])] = tid;
this->order_wdcIndex.insert(std::make_pair(std::make_tuple(this->o_w_id[tid], this->o_d_id[tid], this->o_c_id[tid], this->o_id[tid]), tid));
this->o_c_idIndex.insert(std::make_pair(std::make_tuple(this->o_c_id[tid]), tid));
  }

  // Delete the data
  this->o_id.pop_back();
this->o_d_id.pop_back();
this->o_w_id.pop_back();
this->o_c_id.pop_back();
this->o_entry_d.pop_back();
this->o_carrier_id.pop_back();
this->o_ol_cnt.pop_back();
this->o_all_local.pop_back();
}

uint64_t Order::get(int32_t o_w_id, int32_t o_d_id, int32_t o_id) {
return this->pkIndex[std::make_tuple(o_w_id, o_d_id, o_id)];
}

std::pair<Order::order_wdcIndexType::iterator, Order::order_wdcIndexType::iterator> Order::getByOrder_wdc(int32_t o_w_id, int32_t o_d_id, int32_t o_c_id, int32_t o_id) {
return std::make_pair(
this->order_wdcIndex.lower_bound(std::make_tuple(o_w_id, o_d_id, o_c_id, o_id)),
this->order_wdcIndex.upper_bound(std::make_tuple(o_w_id, o_d_id, o_c_id, o_id)));
}

std::pair<Order::o_c_idIndexType::iterator, Order::o_c_idIndexType::iterator> Order::getByO_c_id(int32_t o_c_id) {
return std::make_pair(
this->o_c_idIndex.lower_bound(std::make_tuple(o_c_id)),
this->o_c_idIndex.upper_bound(std::make_tuple(o_c_id)));
}

}
