#include "yago.h"
#include <unordered_set>
#include <iostream>

size_t Yago::queryWebsitesOfAllWomen() {
  std::unordered_set<str::string, str::hash> women;
  str::string hasGender = facts.predicate_dict.get_string("hasGender");
  str::string female = facts.object_dict.get_string("female");
  str::string hasWebsite = facts.predicate_dict.get_string("hasWebsite");
  size_t websites = 0;

  // Get all women
  size_t i = 0;
  for (auto predicate : facts.predicate) {
    if (predicate == hasGender && facts.object[i] == female) {
      // Store to find website
      women.insert(facts.subject[i]);
    }
    i++;
  }

  // Get all websites
  auto endIterator = women.end();
  i = 0;
  for (auto predicate : facts.predicate) {
    if (predicate == hasWebsite && women.find(facts.subject[i]) != endIterator) {
      websites++;
    }
    i++;
  }

  return websites;
}
