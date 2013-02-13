#ifndef _STR_DICTIONARY_H_
#define _STR_DICTIONARY_H_

#include "equal_to.h"
#include "hash.h"
#include "string.h"
#include "../tuple_less.h"
#include <cstdint>
#include <cstring>
#include <unordered_map>

namespace str {
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

      /** Create an str::string with value stored outside the dictionary */
      string make_inline_string(const char*, size_t) const;

      /** Create an str::string with value stored within the dictionary */
      string make_dictionary_string(const char*, size_t);

      /** Create an str::string with value stored within the dictionary */
      string make_dictionary_string(const char*, size_t, uint64_t) const;

    public:
      /** Placeholder SID if no String is found */
      static const uint64_t NO_VALUE;

      /** Placeholder str::string if no String is found */
      static const string NO_STRING;

      /**
       * Determines the ordering of the given strings.
       *
       * @param lhs Left value
       * @param rhs Right value
       * @return TRUE if left value is less than right value,
       *   FALSE otherwise
       */
      bool less(const string& lhs, const string& rhs) const;

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
      uint64_t get(const char* value) const;

      /**
       * Gets the value of a given String
       *
       * @warning No checks are done to verify that the given String is valid (e.g. belongs to this dictionary)!
       *
       * @param str String to get value of
       * @return String value
       */
      const char* get(const string& str) const;

      /**
       * Gets the string value for a given SID
       *
       * @warning No checks are done to verify that the given SID is valid!
       *
       * @param sid String Identifier to get value for
       * @return String value
       */
      const char* get(const uint64_t sid) const;

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
       * Removes the given String from the Dictionary
       *
       * @warning
       *   No checks are done to verify that the given String
       *   is valid (e.g. belongs to this dictionary)!
       *
       * The String is only actually deleted if it is only
       * referenced once. Otherwise, the reference counter
       * in the index is decreased.
       *
       * @param str String to delete
       */
      void remove(const string& str);

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

      /**
       * Creates a new String and inserts it into the String Dictionary
       *
       * @param value Value to insert into the Dictionary
       * @return Inserted String
       */
      string make_string(const char* value);

      /**
       * Creates a new String for comparison purposes
       *
       * @attention
       *   If the value is not already in the Dictionary,
       *   it is NOT inserted.
       *
       * @param value Value to get String for
       * @return String data structure
       */
      string get_string(const char* value) const;

      /** Destructor */
      ~dictionary();
  };
}

template<> struct element_less<str::string> {
  const str::dictionary* dictionary;

  element_less(const void* argument) : dictionary((str::dictionary*)argument) { }

  bool operator()(const str::string& lhs, const str::string& rhs) const {
    return dictionary->less(lhs, rhs);
  }
};

#endif

