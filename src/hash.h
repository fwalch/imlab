#ifndef _HASH_H_
#define _HASH_H_

template<class T> inline void hash_combine(size_t& seed, T const& value) {
  seed ^= std::hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

#endif
