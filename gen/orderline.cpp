#include <climits>
#include <cstdlib>
#include <cstring>
#include "orderline.h"
#include "../src/schema/conversion.h"

using namespace std;

void OrderlineStore::add(string elements[10]) {
  add_instance(atoi(elements[0].c_str()),
    atoi(elements[1].c_str()),
    atoi(elements[2].c_str()),
    atoi(elements[3].c_str()),
    atoi(elements[4].c_str()),
    atoi(elements[5].c_str()),
    db_stod(elements[6]),
    db_stol(elements[7]),
    db_stol(elements[8]),
    elements[9]);
}

void OrderlineStore::add_instance(int32_t ol_o_id, int32_t ol_d_id, int32_t ol_w_id, int32_t ol_number, int32_t ol_i_id, int32_t ol_supply_w_id, uint64_t ol_delivery_d, int64_t ol_quantity, int64_t ol_amount, std::string ol_dist_info) {
  this->ol_o_id.push_back(ol_o_id);
  this->ol_d_id.push_back(ol_d_id);
  this->ol_w_id.push_back(ol_w_id);
  this->ol_number.push_back(ol_number);
  this->ol_i_id.push_back(ol_i_id);
  this->ol_supply_w_id.push_back(ol_supply_w_id);
  this->ol_delivery_d.push_back(ol_delivery_d);
  this->ol_quantity.push_back(ol_quantity);
  this->ol_amount.push_back(ol_amount);
  this->ol_dist_info.push_back(ol_dist_info);

  pkIndex[std::make_tuple(this->ol_w_id[tid], this->ol_d_id[tid], this->ol_o_id[tid], this->ol_number[tid])] = tid;
  tid++;
}

void OrderlineStore::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->ol_w_id[tid], this->ol_d_id[tid], this->ol_o_id[tid], this->ol_number[tid]);
  auto pkIt = pkIndex.find(pkKey);
  pkIndex.erase(pkIt);

  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->ol_o_id[tid] = this->ol_o_id[tidToSwap];
    this->ol_d_id[tid] = this->ol_d_id[tidToSwap];
    this->ol_w_id[tid] = this->ol_w_id[tidToSwap];
    this->ol_number[tid] = this->ol_number[tidToSwap];
    this->ol_i_id[tid] = this->ol_i_id[tidToSwap];
    this->ol_supply_w_id[tid] = this->ol_supply_w_id[tidToSwap];
    this->ol_delivery_d[tid] = this->ol_delivery_d[tidToSwap];
    this->ol_quantity[tid] = this->ol_quantity[tidToSwap];
    this->ol_amount[tid] = this->ol_amount[tidToSwap];
    this->ol_dist_info.set(tid, this->ol_dist_info[tidToSwap]);

    // Set swapped item's TID in index
    pkIndex[std::make_tuple(this->ol_w_id[tid], this->ol_d_id[tid], this->ol_o_id[tid], this->ol_number[tid])] = tid;
  }

  // Delete the data
  this->ol_o_id.pop_back();
  this->ol_d_id.pop_back();
  this->ol_w_id.pop_back();
  this->ol_number.pop_back();
  this->ol_i_id.pop_back();
  this->ol_supply_w_id.pop_back();
  this->ol_delivery_d.pop_back();
  this->ol_quantity.pop_back();
  this->ol_amount.pop_back();
  this->ol_dist_info.pop_back();
}

uint64_t OrderlineStore::get(int32_t ol_w_id, int32_t ol_d_id, int32_t ol_o_id, int32_t ol_number) {
  return pkIndex[std::make_tuple(ol_w_id, ol_d_id, ol_o_id, ol_number)];
}

std::pair<OrderlineStore::pkIndexType::iterator, OrderlineStore::pkIndexType::iterator> OrderlineStore::get(int32_t ol_w_id, int32_t ol_d_id, int32_t ol_o_id) {
  return std::make_pair(
    pkIndex.lower_bound(std::make_tuple(ol_w_id, ol_d_id, ol_o_id, 0)),
    pkIndex.upper_bound(std::make_tuple(ol_w_id, ol_d_id, ol_o_id, INT_MAX)));
}

