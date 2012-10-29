#include <cassert>
#include <ctime>
#include <iostream>
#include "tpcc.h"
#include "oltp.h"
#include "import.h"
#include "timer.h"

using namespace std;

void assertQueries(Tpcc*, int32_t);
void runTest(Tpcc*);
void createRandomOrders(const int, Tpcc*);

int main() {
  try {
    const int newOrderCount = 1E6;
    Tpcc tpcc;

    importSampleData("data", &tpcc);

    // Check that there are only sample data orders
    assert(tpcc.orders.count() == Orders);

    createRandomOrders(newOrderCount, &tpcc);

    // Finally check that we actually created new orders
    assert(tpcc.orders.count() == Orders + newOrderCount);

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

void runTest(Tpcc* tpcc) {
  assertQueries(tpcc, 3001);

  // Verify that warehouse 4 originally has 50 items of type 1:
  assert(tpcc->stock.s_quantity[tpcc->stock.get(4, 1)] == 50);

  int supware[2] = { 4 };
  int itemid[2] = { 1 };
  int qty[2] = { 10 };
  tpcc->newOrder(4, 1, 1, 1, supware, itemid, qty, 0);

  // Verify execution of NewOrder transaction:
  // we created a new order on warehouse 4, district 1 for customer 1
  // for 1 item of type 1. The item is in warehouse 4 (supware) and we want 10
  // more items. In the sample data there are originally 50 items.

  // -> now only 40 items of type 1 should be in warehouse 4:
  assert(tpcc->stock.s_quantity[tpcc->stock.get(4, 1)] == 40);

  assertQueries(tpcc, 3002);
}

void assertQueries(Tpcc* tpcc, int32_t o_id) {
  // Test if querying retrieves the correct object
  uint64_t order = tpcc->orders.get(4, 2, 28);
  assert(tpcc->orders.o_id[order] == 28);
  assert(tpcc->orders.o_d_id[order] == 2);
  assert(tpcc->orders.o_w_id[order] == 4);
  assert(tpcc->orders.o_c_id[order] == 258);

  // Insert additional item, test if querying still works
  tpcc->orders.add_instance(
    o_id,
    1,
    4,
    2679,
    39,
    0,
    14,
    1
  );

  // Test querying
  order = tpcc->orders.get(4, 1, o_id);
  assert(tpcc->orders.o_id[order] == o_id);
  assert(tpcc->orders.o_d_id[order] == 1);
  assert(tpcc->orders.o_w_id[order] == 4);
  assert(tpcc->orders.o_c_id[order] == 2679);
}
