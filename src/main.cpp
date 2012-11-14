#include <cassert>
#include <ctime>
#include <iostream>
#include "tpcc.h"
#include "oltp.h"
#include "olap.h"
#include "import.h"
#include "timer.h"
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

using namespace std;

uint64_t getTime();
void executeQueries(Tpcc*);
void executeQueriesAndTransactions(Tpcc*);
void executeTransactions(Tpcc*);

const int NewOrderCount = 1E6;
const int QueryCount = 10;

volatile bool childRunning = false;
int executedQueries = 0;

static void SIGCHLD_handler(int signal) {
  if (signal != 17) {
    cout << " ✘  Child terminated with signal " << signal << "." << endl;
  }

  childRunning = false;
}

int main() {
  try {
    struct sigaction sa;
    sa.sa_handler = SIGCHLD_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
      throw "Error while attaching signal.";
    }

    Tpcc tpcc;

    importSampleData("data", &tpcc);

    executeQueries(&tpcc);

    Timer t;
    t.start();
    cout << " ✱ Running " << NewOrderCount << " NewOrder transactions with parallel queries." << endl;

    for (int i = 0; i < NewOrderCount; i++) {
      // Check if child still running every 10000 NewOrders
      if (i%10000 == 0) {
        if (!childRunning) {
          childRunning = true;
          executedQueries++;
          pid_t pid = fork();
          if (!pid) {
            // Child: execute query
            cout << "  ➤ Query result: " << lastNameOrderSum("BARBARBAR", &tpcc) << "." << endl;
            return 0;
          }
        }
      }
      // Parent: run NewOrder transaction
      newOrderRandom(getTime(), urand(1, Warehouses), &tpcc);
    }

    // Wait for child to finish
    while (childRunning);

    t.stop();
    cout << " ✔  Done in " << t.seconds << " sec (" << NewOrderCount/t.seconds << " tps)." << endl;
    cout << "    Executed " << executedQueries << " queries (" << executedQueries/t.seconds << " qps)." << endl;

    return 0;
  }
  catch (string msg) {
    cerr << " ✘ Exception thrown: " << msg << endl;
    return 1;
  }
}

void executeQueries(Tpcc* tpcc) {
  Timer t;
  t.start();
  cout << " ✱ Running " << QueryCount << " queries." << endl;

  for (int i = 0; i < QueryCount; i++) {
    cout << "    Query result: " << lastNameOrderSum("BARBARBAR", tpcc) << "." << endl;
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << QueryCount/t.seconds << " qps)." << endl;
}

void executeTransactions(Tpcc* tpcc) {
  Timer t;
  t.start();
  cout << " ✱ Running " << NewOrderCount << " NewOrder transactions." << endl;

  for (int i = 0; i < NewOrderCount; i++) {
    newOrderRandom(getTime(), urand(1, Warehouses), tpcc);
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << NewOrderCount/t.seconds << " tps)." << endl;
}

uint64_t getTime() {
  return (uint64_t)clock();
}
