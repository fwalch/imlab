#include "store.h"

Store::Store() {
  tid = 0;
}

size_t Store::count() {
  return tid;
}
