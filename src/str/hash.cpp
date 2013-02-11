#include <functional>
#include "hash.h"

namespace str {
  size_t hash::operator()(const char* value) const {
    return std::hash<std::string>()(value);
  }

  size_t hash::operator()(const str::string value) const {
    return std::hash<uint64_t>()(((uint64_t*)&value)[0])
      ^ std::hash<uint64_t>()(((uint64_t*)&value)[1]);
  }
}
