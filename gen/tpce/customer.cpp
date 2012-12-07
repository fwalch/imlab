#include <climits>
#include <cstdlib>
#include <cstring>
#include "customer.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace tpce {

void Customer::add(string elements[24]) {
  add_instance(atoi(elements[0].c_str()), elements[1].c_str(), elements[2].c_str(), elements[3].c_str(), elements[4].c_str(), elements[5].c_str(), elements[6].c_str(), atoi(elements[7].c_str()), db_stod(elements[8]), atoi(elements[9].c_str()), elements[10].c_str(), elements[11].c_str(), elements[12].c_str(), elements[13].c_str(), elements[14].c_str(), elements[15].c_str(), elements[16].c_str(), elements[17].c_str(), elements[18].c_str(), elements[19].c_str(), elements[20].c_str(), elements[21].c_str(), elements[22].c_str(), elements[23].c_str());
}

void Customer::add_instance(int32_t c_id, const char* c_tax_id, const char* c_st_id, const char* c_l_name, const char* c_f_name, const char* c_m_name, const char* c_gndr, int32_t c_tier, uint64_t c_dob, int32_t c_ad_id, const char* c_ctry_1, const char* c_area_1, const char* c_local_1, const char* c_ext_1, const char* c_ctry_2, const char* c_area_2, const char* c_local_2, const char* c_ext_2, const char* c_ctry_3, const char* c_area_3, const char* c_local_3, const char* c_ext_3, const char* c_email_1, const char* c_email_2) {
  this->c_id.push_back(c_id);
auto c_tax_id_str = this->c_tax_id_dict.make_string(c_tax_id);
this->c_tax_id.push_back(c_tax_id_str);
auto c_st_id_str = this->c_st_id_dict.make_string(c_st_id);
this->c_st_id.push_back(c_st_id_str);
auto c_l_name_str = this->c_l_name_dict.make_string(c_l_name);
this->c_l_name.push_back(c_l_name_str);
auto c_f_name_str = this->c_f_name_dict.make_string(c_f_name);
this->c_f_name.push_back(c_f_name_str);
auto c_m_name_str = this->c_m_name_dict.make_string(c_m_name);
this->c_m_name.push_back(c_m_name_str);
auto c_gndr_str = this->c_gndr_dict.make_string(c_gndr);
this->c_gndr.push_back(c_gndr_str);
this->c_tier.push_back(c_tier);
this->c_dob.push_back(c_dob);
this->c_ad_id.push_back(c_ad_id);
auto c_ctry_1_str = this->c_ctry_1_dict.make_string(c_ctry_1);
this->c_ctry_1.push_back(c_ctry_1_str);
auto c_area_1_str = this->c_area_1_dict.make_string(c_area_1);
this->c_area_1.push_back(c_area_1_str);
auto c_local_1_str = this->c_local_1_dict.make_string(c_local_1);
this->c_local_1.push_back(c_local_1_str);
auto c_ext_1_str = this->c_ext_1_dict.make_string(c_ext_1);
this->c_ext_1.push_back(c_ext_1_str);
auto c_ctry_2_str = this->c_ctry_2_dict.make_string(c_ctry_2);
this->c_ctry_2.push_back(c_ctry_2_str);
auto c_area_2_str = this->c_area_2_dict.make_string(c_area_2);
this->c_area_2.push_back(c_area_2_str);
auto c_local_2_str = this->c_local_2_dict.make_string(c_local_2);
this->c_local_2.push_back(c_local_2_str);
auto c_ext_2_str = this->c_ext_2_dict.make_string(c_ext_2);
this->c_ext_2.push_back(c_ext_2_str);
auto c_ctry_3_str = this->c_ctry_3_dict.make_string(c_ctry_3);
this->c_ctry_3.push_back(c_ctry_3_str);
auto c_area_3_str = this->c_area_3_dict.make_string(c_area_3);
this->c_area_3.push_back(c_area_3_str);
auto c_local_3_str = this->c_local_3_dict.make_string(c_local_3);
this->c_local_3.push_back(c_local_3_str);
auto c_ext_3_str = this->c_ext_3_dict.make_string(c_ext_3);
this->c_ext_3.push_back(c_ext_3_str);
auto c_email_1_str = this->c_email_1_dict.make_string(c_email_1);
this->c_email_1.push_back(c_email_1_str);
auto c_email_2_str = this->c_email_2_dict.make_string(c_email_2);
this->c_email_2.push_back(c_email_2_str);
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
this->c_tax_id[tid] = this->c_tax_id[tidToSwap];
this->c_st_id[tid] = this->c_st_id[tidToSwap];
this->c_l_name[tid] = this->c_l_name[tidToSwap];
this->c_f_name[tid] = this->c_f_name[tidToSwap];
this->c_m_name[tid] = this->c_m_name[tidToSwap];
this->c_gndr[tid] = this->c_gndr[tidToSwap];
this->c_tier[tid] = this->c_tier[tidToSwap];
this->c_dob[tid] = this->c_dob[tidToSwap];
this->c_ad_id[tid] = this->c_ad_id[tidToSwap];
this->c_ctry_1[tid] = this->c_ctry_1[tidToSwap];
this->c_area_1[tid] = this->c_area_1[tidToSwap];
this->c_local_1[tid] = this->c_local_1[tidToSwap];
this->c_ext_1[tid] = this->c_ext_1[tidToSwap];
this->c_ctry_2[tid] = this->c_ctry_2[tidToSwap];
this->c_area_2[tid] = this->c_area_2[tidToSwap];
this->c_local_2[tid] = this->c_local_2[tidToSwap];
this->c_ext_2[tid] = this->c_ext_2[tidToSwap];
this->c_ctry_3[tid] = this->c_ctry_3[tidToSwap];
this->c_area_3[tid] = this->c_area_3[tidToSwap];
this->c_local_3[tid] = this->c_local_3[tidToSwap];
this->c_ext_3[tid] = this->c_ext_3[tidToSwap];
this->c_email_1[tid] = this->c_email_1[tidToSwap];
this->c_email_2[tid] = this->c_email_2[tidToSwap];

    // Set swapped item's TID in index
    this->pkIndex[std::make_tuple(this->c_id[tid])] = tid;
  }

  // Delete the data
  this->c_id.pop_back();
auto c_tax_id_sid = this->c_tax_id.back();
this->c_tax_id_dict.remove(c_tax_id_sid);
this->c_tax_id.pop_back();
auto c_st_id_sid = this->c_st_id.back();
this->c_st_id_dict.remove(c_st_id_sid);
this->c_st_id.pop_back();
auto c_l_name_sid = this->c_l_name.back();
this->c_l_name_dict.remove(c_l_name_sid);
this->c_l_name.pop_back();
auto c_f_name_sid = this->c_f_name.back();
this->c_f_name_dict.remove(c_f_name_sid);
this->c_f_name.pop_back();
auto c_m_name_sid = this->c_m_name.back();
this->c_m_name_dict.remove(c_m_name_sid);
this->c_m_name.pop_back();
auto c_gndr_sid = this->c_gndr.back();
this->c_gndr_dict.remove(c_gndr_sid);
this->c_gndr.pop_back();
this->c_tier.pop_back();
this->c_dob.pop_back();
this->c_ad_id.pop_back();
auto c_ctry_1_sid = this->c_ctry_1.back();
this->c_ctry_1_dict.remove(c_ctry_1_sid);
this->c_ctry_1.pop_back();
auto c_area_1_sid = this->c_area_1.back();
this->c_area_1_dict.remove(c_area_1_sid);
this->c_area_1.pop_back();
auto c_local_1_sid = this->c_local_1.back();
this->c_local_1_dict.remove(c_local_1_sid);
this->c_local_1.pop_back();
auto c_ext_1_sid = this->c_ext_1.back();
this->c_ext_1_dict.remove(c_ext_1_sid);
this->c_ext_1.pop_back();
auto c_ctry_2_sid = this->c_ctry_2.back();
this->c_ctry_2_dict.remove(c_ctry_2_sid);
this->c_ctry_2.pop_back();
auto c_area_2_sid = this->c_area_2.back();
this->c_area_2_dict.remove(c_area_2_sid);
this->c_area_2.pop_back();
auto c_local_2_sid = this->c_local_2.back();
this->c_local_2_dict.remove(c_local_2_sid);
this->c_local_2.pop_back();
auto c_ext_2_sid = this->c_ext_2.back();
this->c_ext_2_dict.remove(c_ext_2_sid);
this->c_ext_2.pop_back();
auto c_ctry_3_sid = this->c_ctry_3.back();
this->c_ctry_3_dict.remove(c_ctry_3_sid);
this->c_ctry_3.pop_back();
auto c_area_3_sid = this->c_area_3.back();
this->c_area_3_dict.remove(c_area_3_sid);
this->c_area_3.pop_back();
auto c_local_3_sid = this->c_local_3.back();
this->c_local_3_dict.remove(c_local_3_sid);
this->c_local_3.pop_back();
auto c_ext_3_sid = this->c_ext_3.back();
this->c_ext_3_dict.remove(c_ext_3_sid);
this->c_ext_3.pop_back();
auto c_email_1_sid = this->c_email_1.back();
this->c_email_1_dict.remove(c_email_1_sid);
this->c_email_1.pop_back();
auto c_email_2_sid = this->c_email_2.back();
this->c_email_2_dict.remove(c_email_2_sid);
this->c_email_2.pop_back();
}

uint64_t Customer::get(int32_t c_id) {
return this->pkIndex[std::make_tuple(c_id)];
}

}
