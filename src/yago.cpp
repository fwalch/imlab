#include "yago.h"
#include <set>
#include <iostream>
#include <cstring>

size_t Yago::queryWebsitesOfAllWomen() {
  std::set<std::string> women;
  size_t websites = 0;

  // Get all women
  for (size_t i = 0; i < facts.count(); i++) {
    if (strcmp(facts.predicate[i], "hasGender") == 0 && strcmp(facts.object[i], "female") == 0) {
      // Store to find website
      women.insert(facts.subject[i]);
    }
  }

  // Get all websites
  auto endIterator = women.end();
  for (size_t i = 0; i < facts.count(); i++) {
    if (strcmp(facts.predicate[i], "hasWebsite") == 0 && women.find(facts.subject[i]) != endIterator) {
      websites++;
    }
  }

  return websites;
}
