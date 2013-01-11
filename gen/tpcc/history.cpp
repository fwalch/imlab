#include <climits>
#include <cstdlib>
#include <cstring>
#include "history.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

  void History::add(string elements[8]) {
    add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), atoi(elements[2].c_str()), atoi(elements[3].c_str()), atoi(elements[4].c_str()), db_stod(elements[5]), db_stol(elements[6]), elements[7].c_str());
  }

  void History::add_instance(int32_t h_c_id, int32_t h_c_d_id, int32_t h_c_w_id, int32_t h_d_id, int32_t h_w_id, uint64_t h_date, int64_t h_amount, const char* h_data) {
    this->h_c_id.push_back(h_c_id);
    this->h_c_d_id.push_back(h_c_d_id);
    this->h_c_w_id.push_back(h_c_w_id);
    this->h_d_id.push_back(h_d_id);
    this->h_w_id.push_back(h_w_id);
    this->h_date.push_back(h_date);
    this->h_amount.push_back(h_amount);
    auto h_data_str = this->h_data_dict.make_string(h_data);
    this->h_data.push_back(h_data_str);

    tid++;
  }

  void History::remove(uint64_t tid) {


    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->h_c_id[tid] = this->h_c_id[tidToSwap];
      this->h_c_d_id[tid] = this->h_c_d_id[tidToSwap];
      this->h_c_w_id[tid] = this->h_c_w_id[tidToSwap];
      this->h_d_id[tid] = this->h_d_id[tidToSwap];
      this->h_w_id[tid] = this->h_w_id[tidToSwap];
      this->h_date[tid] = this->h_date[tidToSwap];
      this->h_amount[tid] = this->h_amount[tidToSwap];
      this->h_data[tid] = this->h_data[tidToSwap];

      // Set swapped item's TID in index

    }

    // Delete the data
    this->h_c_id.pop_back();
    this->h_c_d_id.pop_back();
    this->h_c_w_id.pop_back();
    this->h_d_id.pop_back();
    this->h_w_id.pop_back();
    this->h_date.pop_back();
    this->h_amount.pop_back();
    auto h_data_sid = this->h_data.back();
    this->h_data_dict.remove(h_data_sid);
    this->h_data.pop_back();
  }



}
