#ifndef _STR_DICTIONARY_H_
#define _STR_DICTIONARY_H_

#include "equal_to.h"
#include "hash.h"
#include <cstdint>
#include <tuple>
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

    public:
      /** Placeholder SID if no String is found */
      static const uint64_t NO_VALUE;

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
