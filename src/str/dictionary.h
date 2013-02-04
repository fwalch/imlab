#ifndef _STR_DICTIONARY_H_
#define _STR_DICTIONARY_H_

#include <cstdint>
#include <unordered_map>
#include <tuple>
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

  /**
   * Data structure to hold the string dictionary.
   *
   * @sa str::string
   */
  class dictionary {
    private:
      /** Counter for String Identifiers (SIDs) */
      uint64_t sid = 1;

      /**
       * Index for String Identifier (SID) -> string lookup
       *
       * First component of value tuple is a reference
       * counter (i.e. how often the string is used)
       */
      std::unordered_map<uint64_t, std::tuple<uint32_t, const char*>> map;

      /**
       * Index for String -> String Identifier (SID) lookup
       */
      std::unordered_map<const char*, uint64_t, hash, equal_to> reverse_map;

      /** Helper function */
      string make_inline_string(const char*, size_t);

      /** Helper function */
      string make_dictionary_string(const char*, size_t);

    public:
      /** Placeholder SID if no String is found */
      static const uint64_t NO_VALUE = 0;

      /** Placeholder str::string if no String is found */
      static const string NO_STRING;

      /**
       * Inserts the given string value into the Dictionary
       *
       * @param value Value to insert
       * @return String Identifier (SID)
       */
      uint64_t insert(const char* value);

      /**
       * Gets the SID of a given string value
       *
       * @attention str::dictionary::NO_VALUE is returned if no SID is found.
       *
       * @param value Value to get SID of
       * @return String Identifier (SID)
       */
      uint64_t get(const char* value);

      /**
       * Gets the string value for a given SID
       *
       * @warning No checks are done to verify that the given SID is valid!
       *
       * @param sid String Identifier to get value for
       * @return String value
       */
      const char* get(uint64_t sid);

      /**
       * Removes the String with the given SID from the Dictionary
       *
       * @warning No checks are done to verify that the given SID is valid!
       *
       * The String is only actually deleted if it is only
       * referenced once. Otherwise, the reference counter
       * in the index is decreased.
       *
       * @param sid String Identifier to delete
       */
      void remove(uint64_t sid);

      /**
       * Assigns a new value to the String with the given SID
       *
       * @warning No checks are done to verify that the given SID is valid!
       *
       * The parameter sid will be updated with a changed SID value
       * representing the new string value.
       *
       * @param sid String Identifier of the String to be updated
       * @param value New value of the String
       */
      void update(uint64_t& sid, const char* value);

      /** Destructor */
      ~dictionary();
  };
}

#endif
