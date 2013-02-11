#include <functional>
#include "hash.h"
#include "../hash.h"

namespace str {
  size_t hash::operator()(const char* value) const {
    return std::hash<std::string>()(value);
  }
}
