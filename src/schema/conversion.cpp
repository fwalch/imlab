#include "conversion.h"

//TODO: relies on correct number of decimal places in str
uint64_t db_stol(std::string str) {
  size_t pos = str.find('.');
  if (pos != std::string::npos) {
    str = str.erase(pos, 1);
  }
  return atol(str.c_str());
}

uint64_t db_stod(std::string str) {
  return atol(str.c_str());
}
