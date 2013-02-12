#include <climits>
#include <cstdlib>
#include <cstring>
#include "item.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpcc {

  void Item::add(string elements[5]) {
    add_instance(atoi(elements[0].c_str()), atoi(elements[1].c_str()), elements[2].c_str(), db_stol(elements[3]), elements[4].c_str());
  }

  void Item::add_instance(int32_t i_id, int32_t i_im_id, const char* i_name, int64_t i_price, const char* i_data) {
    this->i_id.push_back(i_id);
    this->i_im_id.push_back(i_im_id);
    auto i_name_str = this->i_name_dict.make_string(i_name);
    this->i_name.push_back(i_name_str);
    this->i_price.push_back(i_price);
    auto i_data_str = this->i_data_dict.make_string(i_data);
    this->i_data.push_back(i_data_str);
    this->pkIndex[std::make_tuple(this->i_id[tid])] = tid;
    tid++;
  }

  void Item::remove(uint64_t tid) {
    auto pkKey = std::make_tuple(this->i_id[tid]);
    auto pkIt = this->pkIndex.find(pkKey);
    this->pkIndex.erase(pkIt);

    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->i_id[tid] = this->i_id[tidToSwap];
      this->i_im_id[tid] = this->i_im_id[tidToSwap];
      this->i_name[tid] = this->i_name[tidToSwap];
      this->i_price[tid] = this->i_price[tidToSwap];
      this->i_data[tid] = this->i_data[tidToSwap];

      // Set swapped item's TID in index
      this->pkIndex[std::make_tuple(this->i_id[tid])] = tid;
    }

    // Delete the data
    this->i_id.pop_back();
    this->i_im_id.pop_back();
    auto i_name_sid = this->i_name.back();
    this->i_name_dict.remove(i_name_sid);
    this->i_name.pop_back();
    this->i_price.pop_back();
    auto i_data_sid = this->i_data.back();
    this->i_data_dict.remove(i_data_sid);
    this->i_data.pop_back();
  }

  uint64_t Item::get(int32_t i_id) {
    return this->pkIndex[std::make_tuple(i_id)];
  }

}
