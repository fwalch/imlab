#ifndef _STOCK_H_
#define _STOCK_H_

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cstdint>
#include "store.h"

struct stock_t {
  int32_t s_i_id;
  int32_t s_w_id;
  int64_t s_quantity;
  char s_dist_01[25];
  char s_dist_02[25];
  char s_dist_03[25];
  char s_dist_04[25];
  char s_dist_05[25];
  char s_dist_06[25];
  char s_dist_07[25];
  char s_dist_08[25];
  char s_dist_09[25];
  char s_dist_10[25];
  int64_t s_ytd;
  int64_t s_order_cnt;
  int64_t s_remote_cnt;
  char s_data[51];
};

class Stock : public StoreBase<stock_t> {
  private:
    typedef std::tuple<int32_t, int32_t> pkIndexType;
    std::map<pkIndexType, uint64_t> pkIndex;

  protected:
    void onNewItem(stock_t*, uint64_t);

  public:
    void add(std::string[17]);
    stock_t* get(int32_t, int32_t);
};

#endif
