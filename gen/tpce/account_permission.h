#ifndef _TPCE_ACCOUNT_PERMISSION_H_
#define _TPCE_ACCOUNT_PERMISSION_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace tpce {

  class AccountPermission : public Store {
    public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> ap_ca_id;
    str::vector<4> ap_acl;
    str::vector<20> ap_tax_id;
    str::vector<255> ap_l_name;
    str::vector<255> ap_f_name;

    void add(std::string[5]);
    void add_instance(int32_t ap_ca_id, std::string ap_acl, std::string ap_tax_id, std::string ap_l_name, std::string ap_f_name);
    void remove(uint64_t tid);

    uint64_t get(int32_t ap_ca_id);
  };

}

#endif
