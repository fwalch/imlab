#include <climits>
#include <cstdlib>
#include <cstring>
#include "customer.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpce {

  void Customer::add(string elements[24]) {
    add_instance(atoi(elements[0].c_str()), elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], atoi(elements[7].c_str()), db_stod(elements[8]), atoi(elements[9].c_str()), elements[10], elements[11], elements[12], elements[13], elements[14], elements[15], elements[16], elements[17], elements[18], elements[19], elements[20], elements[21], elements[22], elements[23]);
  }

  void Customer::add_instance(int32_t c_id, std::string c_tax_id, std::string c_st_id, std::string c_l_name, std::string c_f_name, std::string c_m_name, std::string c_gndr, int32_t c_tier, uint64_t c_dob, int32_t c_ad_id, std::string c_ctry_1, std::string c_area_1, std::string c_local_1, std::string c_ext_1, std::string c_ctry_2, std::string c_area_2, std::string c_local_2, std::string c_ext_2, std::string c_ctry_3, std::string c_area_3, std::string c_local_3, std::string c_ext_3, std::string c_email_1, std::string c_email_2) {
    this->c_id.push_back(c_id);
    this->c_tax_id.push_back(c_tax_id);
    this->c_st_id.push_back(c_st_id);
    this->c_l_name.push_back(c_l_name);
    this->c_f_name.push_back(c_f_name);
    this->c_m_name.push_back(c_m_name);
    this->c_gndr.push_back(c_gndr);
    this->c_tier.push_back(c_tier);
    this->c_dob.push_back(c_dob);
    this->c_ad_id.push_back(c_ad_id);
    this->c_ctry_1.push_back(c_ctry_1);
    this->c_area_1.push_back(c_area_1);
    this->c_local_1.push_back(c_local_1);
    this->c_ext_1.push_back(c_ext_1);
    this->c_ctry_2.push_back(c_ctry_2);
    this->c_area_2.push_back(c_area_2);
    this->c_local_2.push_back(c_local_2);
    this->c_ext_2.push_back(c_ext_2);
    this->c_ctry_3.push_back(c_ctry_3);
    this->c_area_3.push_back(c_area_3);
    this->c_local_3.push_back(c_local_3);
    this->c_ext_3.push_back(c_ext_3);
    this->c_email_1.push_back(c_email_1);
    this->c_email_2.push_back(c_email_2);
    this->pkIndex[std::make_tuple(this->c_id[tid])] = tid;
    tid++;
  }

  void Customer::remove(uint64_t tid) {
    auto pkKey = std::make_tuple(this->c_id[tid]);
    auto pkIt = this->pkIndex.find(pkKey);
    this->pkIndex.erase(pkIt);


    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->c_id[tid] = this->c_id[tidToSwap];
      this->c_tax_id.set(tid, this->c_tax_id[tidToSwap]);
      this->c_st_id.set(tid, this->c_st_id[tidToSwap]);
      this->c_l_name.set(tid, this->c_l_name[tidToSwap]);
      this->c_f_name.set(tid, this->c_f_name[tidToSwap]);
      this->c_m_name.set(tid, this->c_m_name[tidToSwap]);
      this->c_gndr.set(tid, this->c_gndr[tidToSwap]);
      this->c_tier[tid] = this->c_tier[tidToSwap];
      this->c_dob[tid] = this->c_dob[tidToSwap];
      this->c_ad_id[tid] = this->c_ad_id[tidToSwap];
      this->c_ctry_1.set(tid, this->c_ctry_1[tidToSwap]);
      this->c_area_1.set(tid, this->c_area_1[tidToSwap]);
      this->c_local_1.set(tid, this->c_local_1[tidToSwap]);
      this->c_ext_1.set(tid, this->c_ext_1[tidToSwap]);
      this->c_ctry_2.set(tid, this->c_ctry_2[tidToSwap]);
      this->c_area_2.set(tid, this->c_area_2[tidToSwap]);
      this->c_local_2.set(tid, this->c_local_2[tidToSwap]);
      this->c_ext_2.set(tid, this->c_ext_2[tidToSwap]);
      this->c_ctry_3.set(tid, this->c_ctry_3[tidToSwap]);
      this->c_area_3.set(tid, this->c_area_3[tidToSwap]);
      this->c_local_3.set(tid, this->c_local_3[tidToSwap]);
      this->c_ext_3.set(tid, this->c_ext_3[tidToSwap]);
      this->c_email_1.set(tid, this->c_email_1[tidToSwap]);
      this->c_email_2.set(tid, this->c_email_2[tidToSwap]);

      // Set swapped item's TID in index
      this->pkIndex[std::make_tuple(this->c_id[tid])] = tid;
    }

    // Delete the data
    this->c_id.pop_back();
    this->c_tax_id.pop_back();
    this->c_st_id.pop_back();
    this->c_l_name.pop_back();
    this->c_f_name.pop_back();
    this->c_m_name.pop_back();
    this->c_gndr.pop_back();
    this->c_tier.pop_back();
    this->c_dob.pop_back();
    this->c_ad_id.pop_back();
    this->c_ctry_1.pop_back();
    this->c_area_1.pop_back();
    this->c_local_1.pop_back();
    this->c_ext_1.pop_back();
    this->c_ctry_2.pop_back();
    this->c_area_2.pop_back();
    this->c_local_2.pop_back();
    this->c_ext_2.pop_back();
    this->c_ctry_3.pop_back();
    this->c_area_3.pop_back();
    this->c_local_3.pop_back();
    this->c_ext_3.pop_back();
    this->c_email_1.pop_back();
    this->c_email_2.pop_back();
  }

  uint64_t Customer::get(int32_t c_id) {
    return this->pkIndex[std::make_tuple(c_id)];
  }

}
