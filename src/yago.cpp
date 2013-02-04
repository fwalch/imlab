#include "yago.h"
#include <set>
#include <iostream>

size_t Yago::queryWebsitesOfAllWomen() {
  std::set<str::string> women;
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
      // Print website
      std::cout << facts.subject_dict.get(facts.subject[i]) << ": " << facts.object_dict.get(facts.object[i]) << std::endl;
      websites++;
    }
    i++;
  }

  return websites;
}
