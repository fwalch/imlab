#include <ctime>
#include "timer.h"

void Timer::start() {
  start_clock = clock();
}

void Timer::stop() {
  ticks = clock() - start_clock;
  seconds = ticks / (double)CLOCKS_PER_SEC;
}
