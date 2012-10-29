#include <cstdlib>
#include <cstring>
#include "history.h"
#include "conversion.h"

using namespace std;

void History::add(string elements[8]) {
  h_c_id.push_back(atoi(elements[0].c_str()));
  h_c_d_id.push_back(atoi(elements[1].c_str()));
  h_c_w_id.push_back(atoi(elements[2].c_str()));
  h_d_id.push_back(atoi(elements[3].c_str()));
  h_w_id.push_back(atoi(elements[4].c_str()));
  h_date.push_back(db_stod(elements[5]));
  h_amount.push_back(db_stol(elements[6]));
  h_data.push_back(elements[7]);

  tid++;
}

