#include "store.h"

Store::Store() {
  tid = 0;
}

Store::~Store() {
}

size_t Store::count() {
  return tid;
}
