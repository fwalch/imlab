#ifndef _TPCE_CUSTOMER_H_
#define _TPCE_CUSTOMER_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace tpce {

  class Customer : public Store {
    public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> c_id;
    str::vector<20> c_tax_id;
    str::vector<4> c_st_id;
    str::vector<25> c_l_name;
    str::vector<20> c_f_name;
    str::vector<1> c_m_name;
    str::vector<1> c_gndr;
    std::vector<int32_t> c_tier;
    std::vector<uint64_t> c_dob;
    std::vector<int32_t> c_ad_id;
    str::vector<3> c_ctry_1;
    str::vector<3> c_area_1;
    str::vector<10> c_local_1;
    str::vector<5> c_ext_1;
    str::vector<3> c_ctry_2;
    str::vector<3> c_area_2;
    str::vector<10> c_local_2;
    str::vector<5> c_ext_2;
    str::vector<3> c_ctry_3;
    str::vector<3> c_area_3;
    str::vector<10> c_local_3;
    str::vector<5> c_ext_3;
    str::vector<50> c_email_1;
    str::vector<50> c_email_2;

    void add(std::string[24]);
    void add_instance(int32_t c_id, std::string c_tax_id, std::string c_st_id, std::string c_l_name, std::string c_f_name, std::string c_m_name, std::string c_gndr, int32_t c_tier, uint64_t c_dob, int32_t c_ad_id, std::string c_ctry_1, std::string c_area_1, std::string c_local_1, std::string c_ext_1, std::string c_ctry_2, std::string c_area_2, std::string c_local_2, std::string c_ext_2, std::string c_ctry_3, std::string c_area_3, std::string c_local_3, std::string c_ext_3, std::string c_email_1, std::string c_email_2);
    void remove(uint64_t tid);

    uint64_t get(int32_t c_id);
  };

}

#endif
