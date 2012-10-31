#ifndef _STORE_H_
#define _STORE_H_

#include <string>
#include <vector>
#include "../tuple_hash.h"

class Store {
  protected:
    uint64_t tid;

  public:
    Store();
    virtual ~Store();
    virtual void add(std::string[]) = 0;
    size_t count();
};

#endif
