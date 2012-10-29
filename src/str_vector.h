#ifndef _STR_VECTOR_H_
#define _STR_VECTOR_H_

#include <vector>
#include <string>

/**
 * Defines a vector for strings of length C.
 *
 * Each string is represented by an array of null-terminated
 * characters of fixed length C+1, all concatenated together
 * in one vector.
 */
template<size_t C> class str_vector : protected std::vector<char> {
  private:
    const size_t realSize = C + 1;
  public:
    void push_back(std::string);
    void push_back(const char*);
    char* operator[](size_t);
};

template<size_t C> char* str_vector<C>::operator[](size_t pos) {
  return &std::vector<char>::operator[](pos * realSize);
}

template<size_t C> void str_vector<C>::push_back(const char* str) {
  size_t i;
  for (i = 0; i < realSize; i++) {
    if (str[i] == '\0') {
      break;
    }
    std::vector<char>::push_back(str[i]);
  }

  for (; i < realSize; i++) {
    std::vector<char>::push_back('\0');
  }
}

template<size_t C> void str_vector<C>::push_back(std::string str) {
  this->push_back(str.c_str());
}

#endif
