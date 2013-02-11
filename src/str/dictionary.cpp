#include "dictionary.h"
#include <cstring>
#include <climits>

namespace str {
  const uint64_t dictionary::NO_VALUE = 0;

  uint64_t dictionary::insert(const char* value) {
    auto reverse_it = reverse_map.find(value);
    if (reverse_it == reverse_map.end()) {
      // String not in dictionary, insert
      char* insertValue = new char[strlen(value) + 1];
      strcpy(insertValue, value);
      map[sid] = std::make_tuple(1, insertValue);
      reverse_map[insertValue] = sid;
      return sid++;
    }
    // String already in dictionary, increase refcount
    uint64_t sid = reverse_it->second;
    std::get<0>(map[sid])++;
    return sid;
  }

  uint64_t dictionary::get(const char* value) {
    auto it = reverse_map.find(value);
    if (it == reverse_map.end()) {
      return NO_VALUE;
    }
    return it->second;
  }

  const char* dictionary::get(uint64_t sid) {
    return std::get<1>(map[sid]);
  }

  void dictionary::remove(uint64_t sid) {
    auto it = map.find(sid);
    if (--std::get<0>(it->second) == 0) {
      // Reference counter is now 0, delete string completely
      const char* value = std::get<1>(it->second);
      auto reverse_it = reverse_map.find(value);
      reverse_map.erase(reverse_it);
      map.erase(it);
      delete[] value;
    }
  }

  void dictionary::update(uint64_t& sid, const char* value) {
    auto it = map.find(sid);
    uint32_t* refCount = &std::get<0>(it->second);
    if (*refCount == 1) {
      // Delete value from index
      const char* oldValue = std::get<1>(it->second);
      auto reverse_it = reverse_map.find(oldValue);
      reverse_map.erase(reverse_it);

      char* newValue;
      size_t valueLength = strlen(value);
      if (strlen(oldValue) == valueLength) {
        // New string has exactly the same length - copy
        // over old string
        newValue = (char*)oldValue;
      }
      else {
        // Allocate new string
        delete[] oldValue;
        newValue = new char[valueLength + 1];
      }

      strcpy(newValue, value);
      map[sid] = std::make_tuple(1, newValue);
      reverse_map[newValue] = sid;
    }
    else {
      // Create new string
      (*refCount)--;
      sid = insert(value);
    }
  }

  dictionary::~dictionary() {
    for (auto it = map.begin(); it != map.end(); it++) {
      const char* ptr = std::get<1>(it->second);
      delete[] ptr;
    }
  }
}
