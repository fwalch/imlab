#include <tuple>

// Code based on http://stackoverflow.com/a/7115547/249642
namespace std {
  namespace {
    template<class T> inline void hash_combine(size_t& seed, T const& value) {
      seed ^= hash<T>()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    template<class T, size_t Index = std::tuple_size<T>::value - 1> struct HashValueImpl {
      static void apply(size_t& seed, T const& tuple) {
        HashValueImpl<T, Index - 1>::apply(seed, tuple);
        hash_combine(seed, get<Index>(tuple));
      }
    };

    template<class T> struct HashValueImpl<T, 0> {
      static void apply(size_t& seed, T const& tuple) {
        hash_combine(seed, get<0>(tuple));
      }
    };
  }

  template <typename ... TT> struct hash<tuple<TT...>> {
    size_t operator()(const tuple<TT...>& t) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, t);
      return seed;
    }
  };
}
