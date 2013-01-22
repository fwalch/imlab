#ifndef _TPCE_ACCOUNT_PERMISSION_H_
#define _TPCE_ACCOUNT_PERMISSION_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/dictionary.h"
#include "schema.h"

namespace tpce {

  class AccountPermission : public Store {
    public:
    typedef std::tuple<int32_t> pkKeyType;
    typedef std::unordered_map<pkKeyType, uint64_t> pkIndexType;
    pkIndexType pkIndex;
    std::vector<int32_t> ap_ca_id;
    std::vector<str::string> ap_acl;
    str::dictionary ap_acl_dict;
    std::vector<str::string> ap_tax_id;
    str::dictionary ap_tax_id_dict;
    std::vector<str::string> ap_l_name;
    str::dictionary ap_l_name_dict;
    std::vector<str::string> ap_f_name;
    str::dictionary ap_f_name_dict;

    void add(std::string[5]);
    void add_instance(int32_t ap_ca_id, const char* ap_acl, const char* ap_tax_id, const char* ap_l_name, const char* ap_f_name);
    void remove(uint64_t tid);

    uint64_t get(int32_t ap_ca_id);
  };

}

#endif
