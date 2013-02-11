#ifndef _STR_EQUAL_TO_H_
#define _STR_EQUAL_TO_H_

namespace str {
  /**
   * Equality calculator for the String Dictionary's index structure.
   *
   * @sa str::dictionary
   */
  struct equal_to {
    /**
     * Determines whether the given strings are equal.
     *
     * @param lhs Lefthand string to compare
     * @param rhs Righthand string to compare
     * @return TRUE if the strings are equal, FALSE otherwise.
     */
    bool operator()(const char* lhs, const char* rhs) const;
  };
}

#endif
