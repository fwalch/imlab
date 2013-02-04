#include <climits>
#include <cstdlib>
#include <cstring>
#include "account_permission.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpce {

  void AccountPermission::add(string elements[5]) {
    add_instance(atoi(elements[0].c_str()), elements[1], elements[2], elements[3], elements[4]);
  }

  void AccountPermission::add_instance(int32_t ap_ca_id, std::string ap_acl, std::string ap_tax_id, std::string ap_l_name, std::string ap_f_name) {
    this->ap_ca_id.push_back(ap_ca_id);
    this->ap_acl.push_back(ap_acl);
    this->ap_tax_id.push_back(ap_tax_id);
    this->ap_l_name.push_back(ap_l_name);
    this->ap_f_name.push_back(ap_f_name);
    this->pkIndex[std::make_tuple(this->ap_ca_id[tid])] = tid;
    tid++;
  }

  void AccountPermission::remove(uint64_t tid) {
    auto pkKey = std::make_tuple(this->ap_ca_id[tid]);
    auto pkIt = this->pkIndex.find(pkKey);
    this->pkIndex.erase(pkIt);


    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->ap_ca_id[tid] = this->ap_ca_id[tidToSwap];
      this->ap_acl.set(tid, this->ap_acl[tidToSwap]);
      this->ap_tax_id.set(tid, this->ap_tax_id[tidToSwap]);
      this->ap_l_name.set(tid, this->ap_l_name[tidToSwap]);
      this->ap_f_name.set(tid, this->ap_f_name[tidToSwap]);

      // Set swapped item's TID in index
      this->pkIndex[std::make_tuple(this->ap_ca_id[tid])] = tid;
    }

    // Delete the data
    this->ap_ca_id.pop_back();
    this->ap_acl.pop_back();
    this->ap_tax_id.pop_back();
    this->ap_l_name.pop_back();
    this->ap_f_name.pop_back();
  }

  uint64_t AccountPermission::get(int32_t ap_ca_id) {
    return this->pkIndex[std::make_tuple(ap_ca_id)];
  }

}
