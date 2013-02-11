#include "equal_to.h"
#include <cstring>

namespace str {
  bool equal_to::operator()(const char* lhs, const char* rhs) const {
    return strcmp(lhs, rhs) == 0;
  }
}
