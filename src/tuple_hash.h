#include "hash.h"
#include <tuple>

// Code based on http://stackoverflow.com/a/7115547/249642
namespace std {
  namespace {
    template<class T, size_t Index = std::tuple_size<T>::value - 1> struct hash_value {
      static void apply(size_t& seed, const T& tuple) {
        hash_value<T, Index - 1>::apply(seed, tuple);
        hash_combine(seed, get<Index>(tuple));
      }
    };

    template<class T> struct hash_value<T, 0> {
      static void apply(size_t& seed, const T& tuple) {
        hash_combine(seed, get<0>(tuple));
      }
    };
  }

  template<typename ... TT> struct hash<tuple<TT...>> {
    size_t operator()(const tuple<TT...>& t) const {
      size_t seed = 0;
      hash_value<tuple<TT...>>::apply(seed, t);
      return seed;
    }
  };
}
