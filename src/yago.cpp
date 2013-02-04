#include "yago.h"
#include <set>
#include <iostream>

size_t Yago::queryWebsitesOfAllWomen() {
  std::set<uint64_t> women;
  uint64_t hasGender = facts.predicate_dict.get("hasGender");
  uint64_t female = facts.object_dict.get("female");
  uint64_t hasWebsite = facts.predicate_dict.get("hasWebsite");
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
