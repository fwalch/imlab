// Generated 2012-11-07 12:31:26 UTC

#include <climits>
#include <cstdlib>
#include <cstring>
#include "warehouse.h"
#include "../src/schema/conversion.h"

using namespace std;

void WarehouseStore::add(string elements[9]) {
  add_instance(atoi(elements[0].c_str()), elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], db_stol(elements[7]), db_stol(elements[8]));
}

void WarehouseStore::add_instance(int32_t w_id, std::string w_name, std::string w_street_1, std::string w_street_2, std::string w_city, std::string w_state, std::string w_zip, int64_t w_tax, int64_t w_ytd) {
  this->w_id.push_back(w_id);
this->w_name.push_back(w_name);
this->w_street_1.push_back(w_street_1);
this->w_street_2.push_back(w_street_2);
this->w_city.push_back(w_city);
this->w_state.push_back(w_state);
this->w_zip.push_back(w_zip);
this->w_tax.push_back(w_tax);
this->w_ytd.push_back(w_ytd);

  pkIndex[std::make_tuple(this->w_id[tid])] = tid;
  tid++;
}

void WarehouseStore::remove(uint64_t tid) {
  auto pkKey = std::make_tuple(this->w_id[tid]);
auto pkIt = pkIndex.find(pkKey);
pkIndex.erase(pkIt);

  // We want to move the last item to the deleted item's position
  // We have one item less now, so decrease TID for next add_instance
  uint64_t tidToSwap = --this->tid;

  if (tid != tidToSwap) {
    // Move data from last item to deleted item's position
    this->w_id[tid] = this->w_id[tidToSwap];
this->w_name.set(tid, this->w_name[tidToSwap]);
this->w_street_1.set(tid, this->w_street_1[tidToSwap]);
this->w_street_2.set(tid, this->w_street_2[tidToSwap]);
this->w_city.set(tid, this->w_city[tidToSwap]);
this->w_state.set(tid, this->w_state[tidToSwap]);
this->w_zip.set(tid, this->w_zip[tidToSwap]);
this->w_tax[tid] = this->w_tax[tidToSwap];
this->w_ytd[tid] = this->w_ytd[tidToSwap];

    // Set swapped item's TID in index
    pkIndex[std::make_tuple(this->w_id[tid])] = tid;
  }

  // Delete the data
  this->w_id.pop_back();
this->w_name.pop_back();
this->w_street_1.pop_back();
this->w_street_2.pop_back();
this->w_city.pop_back();
this->w_state.pop_back();
this->w_zip.pop_back();
this->w_tax.pop_back();
this->w_ytd.pop_back();
}

    uint64_t WarehouseStore::get(int32_t w_id) {
      return pkIndex[std::make_tuple(w_id)];
    }

