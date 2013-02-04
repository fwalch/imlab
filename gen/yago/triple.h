#ifndef _YAGO_TRIPLE_H_
#define _YAGO_TRIPLE_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/dictionary.h"
#include "schema.h"

namespace yago {

  class Triple : public Store {
    public:

    std::vector<uint64_t> subject;
    str::dictionary subject_dict;
    std::vector<uint64_t> predicate;
    str::dictionary predicate_dict;
    std::vector<uint64_t> object;
    str::dictionary object_dict;

    void add(std::string[3]);
    void add_instance(const char* subject, const char* predicate, const char* object);
    void remove(uint64_t tid);


  };

}

#endif
