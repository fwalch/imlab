#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"

struct warehouse_t {
  int32_t w_id;
  char w_name[11];
  char w_street_1[21];
  char w_street_2[21];
  char w_city[21];
  char w_state[3];
  char w_zip[10];
  uint64_t w_tax;
  uint64_t w_ytd;
};

class Warehouses : public StoreBase<warehouse_t> {
  private:
    std::unordered_map<int32_t, warehouse_t*> pkIndex;

  protected:
    void onNewItem(warehouse_t*);

  public:
    void add(std::string[9]);
    warehouse_t* get(int32_t);
};

#endif
