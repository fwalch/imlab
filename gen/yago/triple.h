#ifndef _YAGO_TRIPLE_H_
#define _YAGO_TRIPLE_H_

#include <tuple>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <map>
#include "../../src/str/vector.h"
#include "schema.h"

namespace yago {

  class Triple : public Store {
    public:

    str::vector<100> subject;
    str::vector<23> predicate;
    str::vector<211> object;

    void add(std::string[3]);
    void add_instance(std::string subject, std::string predicate, std::string object);
    void remove(uint64_t tid);


  };

}

#endif
