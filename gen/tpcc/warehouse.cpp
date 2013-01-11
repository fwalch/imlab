#include <climits>
#include <cstdlib>
#include <cstring>
#include "warehouse.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

  void Warehouse::add(string elements[9]) {
    add_instance(atoi(elements[0].c_str()), elements[1].c_str(), elements[2].c_str(), elements[3].c_str(), elements[4].c_str(), elements[5].c_str(), elements[6].c_str(), db_stol(elements[7]), db_stol(elements[8]));
  }

  void Warehouse::add_instance(int32_t w_id, const char* w_name, const char* w_street_1, const char* w_street_2, const char* w_city, const char* w_state, const char* w_zip, int64_t w_tax, int64_t w_ytd) {
    this->w_id.push_back(w_id);
    auto w_name_str = this->w_name_dict.make_string(w_name);
    this->w_name.push_back(w_name_str);
    auto w_street_1_str = this->w_street_1_dict.make_string(w_street_1);
    this->w_street_1.push_back(w_street_1_str);
    auto w_street_2_str = this->w_street_2_dict.make_string(w_street_2);
    this->w_street_2.push_back(w_street_2_str);
    auto w_city_str = this->w_city_dict.make_string(w_city);
    this->w_city.push_back(w_city_str);
    auto w_state_str = this->w_state_dict.make_string(w_state);
    this->w_state.push_back(w_state_str);
    auto w_zip_str = this->w_zip_dict.make_string(w_zip);
    this->w_zip.push_back(w_zip_str);
    this->w_tax.push_back(w_tax);
    this->w_ytd.push_back(w_ytd);
    this->pkIndex[std::make_tuple(this->w_id[tid])] = tid;
    tid++;
  }

  void Warehouse::remove(uint64_t tid) {
    auto pkKey = std::make_tuple(this->w_id[tid]);
    auto pkIt = this->pkIndex.find(pkKey);
    this->pkIndex.erase(pkIt);


    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->w_id[tid] = this->w_id[tidToSwap];
      this->w_name[tid] = this->w_name[tidToSwap];
      this->w_street_1[tid] = this->w_street_1[tidToSwap];
      this->w_street_2[tid] = this->w_street_2[tidToSwap];
      this->w_city[tid] = this->w_city[tidToSwap];
      this->w_state[tid] = this->w_state[tidToSwap];
      this->w_zip[tid] = this->w_zip[tidToSwap];
      this->w_tax[tid] = this->w_tax[tidToSwap];
      this->w_ytd[tid] = this->w_ytd[tidToSwap];

      // Set swapped item's TID in index
      this->pkIndex[std::make_tuple(this->w_id[tid])] = tid;
    }

    // Delete the data
    this->w_id.pop_back();
    auto w_name_sid = this->w_name.back();
    this->w_name_dict.remove(w_name_sid);
    this->w_name.pop_back();
    auto w_street_1_sid = this->w_street_1.back();
    this->w_street_1_dict.remove(w_street_1_sid);
    this->w_street_1.pop_back();
    auto w_street_2_sid = this->w_street_2.back();
    this->w_street_2_dict.remove(w_street_2_sid);
    this->w_street_2.pop_back();
    auto w_city_sid = this->w_city.back();
    this->w_city_dict.remove(w_city_sid);
    this->w_city.pop_back();
    auto w_state_sid = this->w_state.back();
    this->w_state_dict.remove(w_state_sid);
    this->w_state.pop_back();
    auto w_zip_sid = this->w_zip.back();
    this->w_zip_dict.remove(w_zip_sid);
    this->w_zip.pop_back();
    this->w_tax.pop_back();
    this->w_ytd.pop_back();
  }

  uint64_t Warehouse::get(int32_t w_id) {
    return this->pkIndex[std::make_tuple(w_id)];
  }

}
