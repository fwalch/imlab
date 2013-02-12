#include <climits>
#include <cstdlib>
#include <cstring>
#include "triple.h"
#include "../../src/schema/conversion.h"

using namespace std;

namespace yago {

  void Triple::add(string elements[3]) {
    add_instance(elements[0].c_str(), elements[1].c_str(), elements[2].c_str());
  }

  void Triple::add_instance(const char* subject, const char* predicate, const char* object) {
    auto subject_str = this->subject_dict.make_string(subject);
    this->subject.push_back(subject_str);
    auto predicate_str = this->predicate_dict.make_string(predicate);
    this->predicate.push_back(predicate_str);
    auto object_str = this->object_dict.make_string(object);
    this->object.push_back(object_str);

    tid++;
  }

  void Triple::remove(uint64_t tid) {

    // We want to move the last item to the deleted item's position
    // We have one item less now, so decrease TID for next add_instance
    uint64_t tidToSwap = --this->tid;

    if (tid != tidToSwap) {
      // Move data from last item to deleted item's position
      this->subject[tid] = this->subject[tidToSwap];
      this->predicate[tid] = this->predicate[tidToSwap];
      this->object[tid] = this->object[tidToSwap];

      // Set swapped item's TID in index

    }

    // Delete the data
    auto subject_sid = this->subject.back();
    this->subject_dict.remove(subject_sid);
    this->subject.pop_back();
    auto predicate_sid = this->predicate.back();
    this->predicate_dict.remove(predicate_sid);
    this->predicate.pop_back();
    auto object_sid = this->object.back();
    this->object_dict.remove(object_sid);
    this->object.pop_back();
  }

}
