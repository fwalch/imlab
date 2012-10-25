#include <cstdlib>
#include <cstring>
#include "history.h"
#include "conversion.h"

using namespace std;

void History::add(string elements[8]) {
  history_t history;

  history.h_c_id = atoi(elements[0].c_str());
  history.h_c_d_id = atoi(elements[1].c_str());
  history.h_c_w_id = atoi(elements[2].c_str());
  history.h_d_id = atoi(elements[3].c_str());
  history.h_w_id = atoi(elements[4].c_str());
  history.h_date = db_stod(elements[5]);
  history.h_amount = db_stol(elements[6]);
  strcpy(history.h_data, elements[7].c_str());

  StoreBase::add_instance(history);
}

void History::onNewItem(history_t* item) {
}

