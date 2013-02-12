#ifndef _TUPLE_LESS_H_
#define _TUPLE_LESS_H_

#include <tuple>

template<typename T> struct element_less {
  void* argument;

  element_less(void* argument) : argument(argument) { }

  bool operator()(const T &lhs, const T &rhs) const {
    return std::less<T>()(lhs, rhs);
  }
};

template<typename T, size_t Index = std::tuple_size<T>::value - 1> struct tuple_less {
  void** arguments;

  tuple_less(void** arguments) : arguments(arguments) { }

  bool operator()(const T &lhs, const T &rhs) {
    return tuple_less<T, Index - 1>(arguments)(lhs, rhs)
      || element_less<typename std::tuple_element<Index, T>::type>(arguments[Index])(std::get<Index>(lhs), std::get<Index>(rhs));
  }
};

template<typename T> struct tuple_less<T, 0> {
  void** arguments;

  tuple_less(void** arguments) : arguments(arguments) { }

  bool operator()(const T &lhs, const T &rhs) {
    return element_less<typename std::tuple_element<0, T>::type>(arguments[0])(std::get<0>(lhs), std::get<0>(rhs));
  }
};

#endif
