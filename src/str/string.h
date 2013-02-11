#ifndef _STR_STRING_H_
#define _STR_STRING_H_

#include <cstdint>

namespace str {
  /**
   * Data structure for holding a String Dictionary String
   *
   * Short strings (<15 characters) are stored within the data structure,
   * longer strings are stored within an accompanying String Dictionary.
   *
   * @sa str::dictionary
   */
  union string {
    /** Long string version */
    struct {
      /** 0xFF (indicating a long string) */
      uint8_t flags;
      /** First three characters of string */
      char head[3];
      /** Length of the string (without NULL terminator) */
      uint32_t length;
      /** String Identifier (SID) within the accompanying String Dictionary */
      uint64_t sid;
    };
    /** Short string version */
    struct {
      /** Length of the string (without NULL terminator) */
      uint8_t len;
      /** String content (including NULL terminator) */
      char value[15];
    };

    /**
     * Compares a given String with the current instance.
     *
     * @param str String to compare current instance to.
     * @return TRUE if current instance is equal to given
     *   String, FALSE otherwise.
     */
    bool operator==(const string& str) const;

    /**
     * Compares a given String with the current instance.
     *
     * @param str String to compare current instance to.
     * @return TRUE if current instance is less than given
     *   String, FALSE otherwise.
     */
    bool operator<(const string& str) const;
  };
}

#endif
