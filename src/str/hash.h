#ifndef _STR_HASH_H_
#define _STR_HASH_H_

#include <string>

namespace str {
  /**
   * Hash function calculator for the String Dictionary's index structure.
   *
   * @sa str::dictionary
   */
  struct hash {
    /**
     * Calculates the hash value of the given string value.
     *
     * @param value String value to calculate hash value for.
     * @return Hash value of the given string.
     */
    size_t operator()(const char* value) const;
  };
}

#endif
