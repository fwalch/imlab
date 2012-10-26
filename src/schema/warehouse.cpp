#include <cstdlib>
#include <cstring>
#include "warehouse.h"
#include "conversion.h"

using namespace std;

void Warehouses::add(string elements[9]) {
  warehouse_t warehouse;

  warehouse.w_id = atoi(elements[0].c_str());
  strcpy(warehouse.w_name, elements[1].c_str());
  strcpy(warehouse.w_street_1, elements[2].c_str());
  strcpy(warehouse.w_street_2, elements[3].c_str());
  strcpy(warehouse.w_city, elements[4].c_str());
  strcpy(warehouse.w_state, elements[5].c_str());
  strcpy(warehouse.w_zip, elements[6].c_str());
  warehouse.w_tax = db_stol(elements[7]);
  warehouse.w_ytd = db_stol(elements[8]);

  StoreBase::add_instance(warehouse);
}

void Warehouses::onNewItem(warehouse_t* item, uint64_t tid) {
  pkIndex[item->w_id] = tid;
}

warehouse_t* Warehouses::get(int32_t w_id) {
  return &store[pkIndex[w_id]];
}
