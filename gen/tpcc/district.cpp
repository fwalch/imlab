#include <climits>
#include <cstdlib>
#include <cstring>
#include "district.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

  void District::add(string elements[11]) {
    add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), elements[2].c_str(), elements[3].c_str(), elements[4].c_str(), elements[5].c_str(), elements[6].c_str(), elements[7].c_str(), db_stol(elements[8]), db_stol(elements[9]), atoi(elements[10].c_str()));
  }

  void District::add_instance(int32_t d_id, int32_t d_w_id, const char* d_name, const char* d_street_1, const char* d_street_2, const char* d_city, const char* d_state, const char* d_zip, int64_t d_tax, int64_t d_ytd, int32_t d_next_o_id) {
    this->d_id.push_back(d_id);
    this->d_w_id.push_back(d_w_id);
    auto d_name_str = this->d_name_dict.make_string(d_name);
    this->d_name.push_back(d_name_str);
    auto d_street_1_str = this->d_street_1_dict.make_string(d_street_1);
    this->d_street_1.push_back(d_street_1_str);
    auto d_street_2_str = this->d_street_2_dict.make_string(d_street_2);
    this->d_street_2.push_back(d_street_2_str);
    auto d_city_str = this->d_city_dict.make_string(d_city);
    this->d_city.push_back(d_city_str);
    auto d_state_str = this->d_state_dict.make_string(d_state);
    this->d_state.push_back(d_state_str);
    auto d_zip_str = this->d_zip_dict.make_string(d_zip);
    this->d_zip.push_back(d_zip_str);
    this->d_tax.push_back(d_tax);
    this->d_ytd.push_back(d_ytd);
    this->d_next_o_id.push_back(d_next_o_id);
    this->pkIndex[std::make_tuple(this->d_w_id[tid], this->d_id[tid])] = tid;
    tid++;
  }

  void District::remove(uint64_t tid) {
    auto pkKey = std::make_tuple(this->d_w_id[tid], this->d_id[tid]);
    auto pkIt = this->pkIndex.find(pkKey);
    this->pkIndex.erase(pkIt);


    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->d_id[tid] = this->d_id[tidToSwap];
      this->d_w_id[tid] = this->d_w_id[tidToSwap];
      this->d_name[tid] = this->d_name[tidToSwap];
      this->d_street_1[tid] = this->d_street_1[tidToSwap];
      this->d_street_2[tid] = this->d_street_2[tidToSwap];
      this->d_city[tid] = this->d_city[tidToSwap];
      this->d_state[tid] = this->d_state[tidToSwap];
      this->d_zip[tid] = this->d_zip[tidToSwap];
      this->d_tax[tid] = this->d_tax[tidToSwap];
      this->d_ytd[tid] = this->d_ytd[tidToSwap];
      this->d_next_o_id[tid] = this->d_next_o_id[tidToSwap];

      // Set swapped item's TID in index
      this->pkIndex[std::make_tuple(this->d_w_id[tid], this->d_id[tid])] = tid;
    }

    // Delete the data
    this->d_id.pop_back();
    this->d_w_id.pop_back();
    auto d_name_sid = this->d_name.back();
    this->d_name_dict.remove(d_name_sid);
    this->d_name.pop_back();
    auto d_street_1_sid = this->d_street_1.back();
    this->d_street_1_dict.remove(d_street_1_sid);
    this->d_street_1.pop_back();
    auto d_street_2_sid = this->d_street_2.back();
    this->d_street_2_dict.remove(d_street_2_sid);
    this->d_street_2.pop_back();
    auto d_city_sid = this->d_city.back();
    this->d_city_dict.remove(d_city_sid);
    this->d_city.pop_back();
    auto d_state_sid = this->d_state.back();
    this->d_state_dict.remove(d_state_sid);
    this->d_state.pop_back();
    auto d_zip_sid = this->d_zip.back();
    this->d_zip_dict.remove(d_zip_sid);
    this->d_zip.pop_back();
    this->d_tax.pop_back();
    this->d_ytd.pop_back();
    this->d_next_o_id.pop_back();
  }

  uint64_t District::get(int32_t d_w_id, int32_t d_id) {
    return this->pkIndex[std::make_tuple(d_w_id, d_id)];
  }

}
