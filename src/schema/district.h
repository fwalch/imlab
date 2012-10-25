#ifndef _DISTRICT_H_
#define _DISTRICT_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "store.h"

struct district_t {
  int32_t d_id;
  int32_t d_w_id;
  char d_name[11];
  char d_street_1[21];
  char d_street_2[21];
  char d_city[21];
  char d_state[3];
  char d_zip[9];
  int64_t d_tax;
  int64_t d_ytd;
  int32_t d_next_o_id;
};

class Districts : public StoreBase<district_t> {
  private:
    std::unordered_map<int32_t, std::unordered_map<int32_t, district_t*> > pkIndex;

  protected:
    void onNewItem(district_t*);

  public:
    void add(std::string[11]);
    district_t* get(int32_t, int32_t);
};

#endif
