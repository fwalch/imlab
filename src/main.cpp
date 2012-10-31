#include <cassert>
#include <ctime>
#include <iostream>
#include "tpcc.h"
#include "oltp.h"
#include "import.h"
#include "timer.h"

using namespace std;

void createRandomOrders(const int, Tpcc*);
void createRandomDeliveries(const int, Tpcc*);

int main() {
  const int runs = 1E6;
  const int newOrderCount = runs * 0.9;
  const int deliveryCount = runs * 0.1;

  try {
    Tpcc tpcc;

    importSampleData("data", &tpcc);

    createRandomOrders(newOrderCount, &tpcc);
    createRandomDeliveries(deliveryCount, &tpcc);

    return 0;
  }
  catch (string msg) {
    cerr << " ✘ Exception thrown: " << msg << endl;
    return 1;
  }
}

void createRandomOrders(const int newOrderCount, Tpcc* tpcc) {
  Timer t;
  t.start();
  cout << " ✱ Creating " << newOrderCount << " new random orders." << endl;

  for (int i = 0; i < newOrderCount; i++) {
    newOrderRandom(clock(), urand(1, Warehouses), tpcc);
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << newOrderCount/t.seconds << " orders per second)." << endl;
}

void createRandomDeliveries(const int newDeliveryCount, Tpcc* tpcc) {
  Timer t;
  t.start();
  cout << " ✱ Creating " << newDeliveryCount << " new random deliveries." << endl;

  for (int i = 0; i < newDeliveryCount; i++) {
    deliveryRandom(clock(), urand(1, Warehouses), tpcc);
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << newDeliveryCount/t.seconds << " deliveries per second)." << endl;
}

