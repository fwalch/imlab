#include <cstdlib>
#include <sstream>
#include "conversion.h"

int64_t db_stol(std::string str) {
  size_t pos = str.find('.');
  if (pos != std::string::npos) {
    str = str.erase(pos, 1);
  }
  return atol(str.c_str());
}

uint64_t db_stod(std::string str) {
  std::stringstream ss(str);
  uint64_t value;
  ss >> value;
  return value;
}
