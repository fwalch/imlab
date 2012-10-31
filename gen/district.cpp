// Generated 2012-11-07 12:31:26 UTC

#include <climits>
#include <cstdlib>
#include <cstring>
#include "district.h"
#include "../src/schema/conversion.h"

using namespace std;

void DistrictStore::add(string elements[11]) {
  add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), elements[2], elements[3], elements[4], elements[5], elements[6], elements[7], db_stol(elements[8]), db_stol(elements[9]), atoi(elements[10].c_str()));
}

void DistrictStore::add_instance(int32_t d_id, int32_t d_w_id, std::string d_name, std::string d_street_1, std::string d_street_2, std::string d_city, std::string d_state, std::string d_zip, int64_t d_tax, int64_t d_ytd, int32_t d_next_o_id) {
  this->d_id.push_back(d_id);
this->d_w_id.push_back(d_w_id);
this->d_name.push_back(d_name);
this->d_street_1.push_back(d_street_1);
this->d_street_2.push_back(d_street_2);
this->d_city.push_back(d_city);
this->d_state.push_back(d_state);
this->d_zip.push_back(d_zip);
this->d_tax.push_back(d_tax);
this->d_ytd.push_back(d_ytd);
this->d_next_o_id.push_back(d_next_o_id);

  pkIndex[std::make_tuple(this->d_w_id[tid], this->d_id[tid])] = tid;
  tid++;
}

void DistrictStore::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->d_w_id[tid], this->d_id[tid]);
auto pkIt = pkIndex.find(pkKey);
pkIndex.erase(pkIt);

  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->d_id[tid] = this->d_id[tidToSwap];
this->d_w_id[tid] = this->d_w_id[tidToSwap];
this->d_name.set(tid, this->d_name[tidToSwap]);
this->d_street_1.set(tid, this->d_street_1[tidToSwap]);
this->d_street_2.set(tid, this->d_street_2[tidToSwap]);
this->d_city.set(tid, this->d_city[tidToSwap]);
this->d_state.set(tid, this->d_state[tidToSwap]);
this->d_zip.set(tid, this->d_zip[tidToSwap]);
this->d_tax[tid] = this->d_tax[tidToSwap];
this->d_ytd[tid] = this->d_ytd[tidToSwap];
this->d_next_o_id[tid] = this->d_next_o_id[tidToSwap];

    // Set swapped item's TID in index
    pkIndex[std::make_tuple(this->d_w_id[tid], this->d_id[tid])] = tid;
  }

  // Delete the data
  this->d_id.pop_back();
this->d_w_id.pop_back();
this->d_name.pop_back();
this->d_street_1.pop_back();
this->d_street_2.pop_back();
this->d_city.pop_back();
this->d_state.pop_back();
this->d_zip.pop_back();
this->d_tax.pop_back();
this->d_ytd.pop_back();
this->d_next_o_id.pop_back();
}

    uint64_t DistrictStore::get(int32_t d_w_id, int32_t d_id) {
      return pkIndex[std::make_tuple(d_w_id, d_id)];
    }

