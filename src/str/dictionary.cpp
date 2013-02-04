#include "dictionary.h"
#include <string>
#include <cstring>
#include <climits>

namespace str {
  bool string::operator<(const string &other) const {
    //TODO: sort alphabetically
    return memcmp(this, &other, sizeof(string)) < 0;
  }

  bool string::operator==(const string &other) const {
    return memcmp(this, &other, sizeof(string)) == 0;
  }

  size_t hash::operator()(const char* value) const {
    return std::hash<std::string>()(value);
  }

  bool equal_to::operator()(const char* lhs, const char* rhs) const {
    return strcmp(lhs, rhs) == 0;
  }

  string dictionary::make_string(const char* value) {
    auto len = strlen(value);
    string string;
    if (len < 15) {
      string.len = (uint8_t)len;
      strcpy(string.value, value);
      if (len != 14) {
        memset(string.value + len, 0, 15 - len);
      }
    }
    else if (len < UINT_MAX) {
      string.len = 0xFF;
      // TODO: what if string has only length <3?
      memcpy(string.head, value, 3);
      string.length = (uint32_t)len;
      // TODO: First 3 characters already stored in string structure,
      // so don't store in dictionary (?)
      string.sid = this->insert(value);
    }
    else {
      throw "String too long; cannot proceed";
    }
    return string;
  }

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

  const char* dictionary::get(string &str) {
    if (str.len == 0xFF) {
      return get(str.sid);
    }
    return str.value;
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

  void dictionary::remove(string &str) {
    if (str.len == 0xFF) {
      remove(str.sid);
    }
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
      // Update string
      // TODO: optimize if new string fits into memory of old
      const char* oldValue = std::get<1>(it->second);
      auto reverse_it = reverse_map.find(oldValue);
      reverse_map.erase(reverse_it);
      delete[] oldValue;

      char* newValue = new char[strlen(value) + 1];
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