#ifndef _STR_DICTIONARY_H_
#define _STR_DICTIONARY_H_

#include <cstdint>
#include <unordered_map>
#include <tuple>

namespace str {
  union string {
    struct {
      uint8_t flags;
      char head[3];
      uint32_t length;
      uint64_t sid;
    };
    struct {
      uint8_t len;
      char value[15];
    };
    bool operator<(const string&) const;
  };

  class dictionary {
    private:
      uint64_t sid = 1;
      std::unordered_map<uint64_t, std::tuple<uint32_t, char*>> map;
      std::unordered_map<uint64_t, uint64_t> reverse_map;
    public:
      static const uint64_t NO_VALUE = 0;
      uint64_t insert(const char*);
      uint64_t get(const char*);
      const char* get(string&);
      const char* get(uint64_t);
      void remove(uint64_t);
      void remove(string&);
      void update(uint64_t&, const char*);
      string make_string(const char*);
      ~dictionary();
  };
}

#endif
