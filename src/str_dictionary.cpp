#include "str_dictionary.h"
#include <string>
#include <cstring>
#include <climits>

namespace str {
  bool string::operator<(const string &other) const {
    return memcmp(this, &other, sizeof(string)) < 0;
  }

  string dictionary::make_string(const char* str) {
    auto len = strlen(str);
    string string;
    if (len < 15) {
      string.len = (uint8_t)len;
      strcpy(string.value, str);
      if (len != 14) {
        memset(string.value + len, 0, 15 - len);
      }
    }
    else if (len < UINT_MAX) {
      string.len = 0xFF;
      memcpy(string.head, str, 3);
      string.length = (uint32_t)len;
      // TODO: First 3 characters already stored in string structure,
      // so don't store in dictionary (?)
      string.sid = this->insert(str);
    }
    else {
      throw "String too long; cannot proceed";
    }
    return string;
  }

  uint64_t dictionary::insert(const char* str) {
    auto hash = std::hash<std::string>()(str);
    auto reverse_it = reverse_map.find(hash);
    if (reverse_it == reverse_map.end()) {
      // String not in dictionary, insert
      char* storedString = new char[strlen(str) + 1];
      strcpy(storedString, str);
      map[sid] = std::make_tuple(1, storedString);
      reverse_map[hash] = sid;
      return sid++;
    }
    // String already in dictionary, increase refcount
    auto sid = reverse_it->second;
    std::get<0>(map[sid])++;
    return sid;
  }

  const char* dictionary::get(string &str) {
    if (str.len == 0xFF) {
      return get(str.sid);
    }
    return str.value;
  }

  uint64_t dictionary::get(const char* str) {
    auto hash = std::hash<std::string>()(str);
    auto it = reverse_map.find(hash);
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
      char* str = std::get<1>(it->second);
      auto reverse_it = reverse_map.find(std::hash<std::string>()(str));
      reverse_map.erase(reverse_it);
      map.erase(it);
      delete[] str;
    }
  }

  void dictionary::update(uint64_t& sid, const char* newStr) {
    auto it = map.find(sid);
    uint32_t* refCount = &std::get<0>(it->second);
    if (*refCount == 1) {
      // Update string
      // TODO: optimize if new string fits into memory of old
      char* str = std::get<1>(it->second);
      auto reverse_it = reverse_map.find(std::hash<std::string>()(str));
      reverse_map.erase(reverse_it);
      delete[] str;

      str = new char[strlen(newStr) + 1];
      strcpy(str, newStr);
      map[sid] = std::make_tuple(1, str);
      auto hash = std::hash<std::string>()(str);
      reverse_map[hash] = sid;
    }
    else {
      // Create new string
      (*refCount)--;
      sid = insert(newStr);
    }
  }

  dictionary::~dictionary() {
    for (auto it = map.begin(); it != map.end(); it++) {
      char* ptr = std::get<1>(it->second);
      delete[] ptr;
    }
  }
}
