#include <climits>
#include <cstdlib>
#include <cstring>
#include "triple.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace yago {

  void Triple::add(string elements[3]) {
    add_instance(elements[0], elements[1], elements[2]);
  }

  void Triple::add_instance(std::string subject, std::string predicate, std::string object) {
    this->subject.push_back(subject);
    this->predicate.push_back(predicate);
    this->object.push_back(object);

    tid++;
  }

  void Triple::remove(uint64_t tid) {


    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->subject.set(tid, this->subject[tidToSwap]);
      this->predicate.set(tid, this->predicate[tidToSwap]);
      this->object.set(tid, this->object[tidToSwap]);

      // Set swapped item's TID in index

    }

    // Delete the data
    this->subject.pop_back();
    this->predicate.pop_back();
    this->object.pop_back();
  }



}
