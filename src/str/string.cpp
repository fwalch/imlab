#include "string.h"
#include <cstring>

namespace str {
  bool string::operator==(const string &other) const {
    return (((uint64_t*)&other)[0] ^ ((uint64_t*)this)[0]) == 0
      && (((uint64_t*)&other)[1] ^ ((uint64_t*)this)[1]) == 0;
  }

  bool string::operator<(const string &other) const {
    return memcmp(this, &other, sizeof(string)) < 0;
  }
}
