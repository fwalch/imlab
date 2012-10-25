#include <cstdlib>
#include <cstring>
#include "item.h"
#include "conversion.h"

using namespace std;

void Items::add(string elements[5]) {
  item_t item;

  item.i_id = atoi(elements[0].c_str());
  item.i_im_id = atoi(elements[1].c_str());
  strcpy(item.i_name, elements[2].c_str());
  item.i_im_id = db_stol(elements[3]);
  strcpy(item.i_data, elements[4].c_str());

  StoreBase::add_instance(item);
}

void Items::onNewItem(item_t* item) {
  pkIndex[item->i_id] = item;
}

item_t* Items::get(int32_t i_id) {
  return pkIndex[i_id];
}
