#ifndef _HASH_H_
#define _HASH_H_

#include <functional>
#include <cstddef>

// Code based on http://stackoverflow.com/a/7115547/249642
template<class T> inline void hash_combine(size_t& seed, const T& value) {
  seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

#endif
