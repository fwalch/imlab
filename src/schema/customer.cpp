#include <cstdlib>
#include <cstring>
#include "customer.h"
#include "conversion.h"

using namespace std;

void Customers::add(string elements[21]) {
  customer_t customer;
  int c_id = atoi(elements[0].c_str());
  customer.c_id = c_id;
  int c_d_id = atoi(elements[1].c_str());
  customer.c_d_id = c_d_id;
  int c_w_id = atoi(elements[2].c_str());
  customer.c_w_id = c_w_id;
  strcpy(customer.c_first, elements[3].c_str());
  strcpy(customer.c_middle, elements[4].c_str());
  strcpy(customer.c_last, elements[5].c_str());
  strcpy(customer.c_street_1, elements[6].c_str());
  strcpy(customer.c_street_2, elements[7].c_str());
  strcpy(customer.c_city, elements[8].c_str());
  strcpy(customer.c_state, elements[9].c_str());
  strcpy(customer.c_zip, elements[10].c_str());
  strcpy(customer.c_phone, elements[11].c_str());
  customer.c_since = db_stod(elements[12]);
  strcpy(customer.c_credit, elements[13].c_str());
  customer.c_credit_lim = db_stol(elements[14]);
  customer.c_discount = db_stol(elements[15]);
  customer.c_balance = db_stol(elements[16]);
  customer.c_ytd_paymenr = db_stol(elements[17]);
  customer.c_payment_cnt = db_stol(elements[18]);
  customer.c_delivery_cnt = db_stol(elements[19]);
  strcpy(customer.c_data, elements[20].c_str());

  StoreBase::add_instance(customer);
}

void Customers::onNewItem(customer_t* item) {
  pkIndex[item->c_w_id][item->c_d_id][item->c_id] = item;
}

customer_t* Customers::get(int32_t c_w_id, int32_t c_d_id, int32_t c_id) {
  return pkIndex[c_w_id][c_d_id][c_id];
}
