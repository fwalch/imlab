#ifndef _TPCE_CUSTOMER_H_
#define _TPCE_CUSTOMER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/dictionary.h"
#include "schema.h"

namespace tpce {

  class Customer : public Store {
    public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;

    std::vector<int32_t> c_id;
    std::vector<str::string> c_tax_id;
    str::dictionary c_tax_id_dict;
    std::vector<str::string> c_st_id;
    str::dictionary c_st_id_dict;
    std::vector<str::string> c_l_name;
    str::dictionary c_l_name_dict;
    std::vector<str::string> c_f_name;
    str::dictionary c_f_name_dict;
    std::vector<str::string> c_m_name;
    str::dictionary c_m_name_dict;
    std::vector<str::string> c_gndr;
    str::dictionary c_gndr_dict;
    std::vector<int32_t> c_tier;
    std::vector<uint64_t> c_dob;
    std::vector<int32_t> c_ad_id;
    std::vector<str::string> c_ctry_1;
    str::dictionary c_ctry_1_dict;
    std::vector<str::string> c_area_1;
    str::dictionary c_area_1_dict;
    std::vector<str::string> c_local_1;
    str::dictionary c_local_1_dict;
    std::vector<str::string> c_ext_1;
    str::dictionary c_ext_1_dict;
    std::vector<str::string> c_ctry_2;
    str::dictionary c_ctry_2_dict;
    std::vector<str::string> c_area_2;
    str::dictionary c_area_2_dict;
    std::vector<str::string> c_local_2;
    str::dictionary c_local_2_dict;
    std::vector<str::string> c_ext_2;
    str::dictionary c_ext_2_dict;
    std::vector<str::string> c_ctry_3;
    str::dictionary c_ctry_3_dict;
    std::vector<str::string> c_area_3;
    str::dictionary c_area_3_dict;
    std::vector<str::string> c_local_3;
    str::dictionary c_local_3_dict;
    std::vector<str::string> c_ext_3;
    str::dictionary c_ext_3_dict;
    std::vector<str::string> c_email_1;
    str::dictionary c_email_1_dict;
    std::vector<str::string> c_email_2;
    str::dictionary c_email_2_dict;

    void add(std::string[24]);
    void add_instance(int32_t c_id, const char* c_tax_id, const char* c_st_id, const char* c_l_name, const char* c_f_name, const char* c_m_name, const char* c_gndr, int32_t c_tier, uint64_t c_dob, int32_t c_ad_id, const char* c_ctry_1, const char* c_area_1, const char* c_local_1, const char* c_ext_1, const char* c_ctry_2, const char* c_area_2, const char* c_local_2, const char* c_ext_2, const char* c_ctry_3, const char* c_area_3, const char* c_local_3, const char* c_ext_3, const char* c_email_1, const char* c_email_2);
    void remove(uint64_t tid);

    uint64_t get(int32_t c_id);
  };

}

#endif
