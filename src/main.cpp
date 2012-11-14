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
    Tpcc tpcc;

    importSampleData("data", &tpcc);

    struct sigaction sa;
    sa.sa_handler = SIGCHLD_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
      throw "Error while attaching signal.";
    }

    /*
     * Execute queries
     */
    Timer t;
    t.start();
    cout << " ✱ Running " << QueryCount << " queries." << endl;

    for (int i = 0; i < QueryCount; i++) {
      cout << "    Query result: " << lastNameOrderSum("BARBARBAR", &tpcc) << "." << endl;
    }

    t.stop();
    cout << " ✔  Done in " << t.seconds << " sec (" << QueryCount/t.seconds << " qps)." << endl;

    /*
     * Run queries and transactions in parallel
     */
    t.start();
    cout << " ✱ Running " << QueryCount << " queries and " << NewOrderCount << " NewOrder transactions in parallel." << endl;

    for (int i = 0; i < NewOrderCount; i++) {
      // Check if child still running every 10000 NewOrders
      if (i%10000 == 0) {
        if (!childRunning && executedQueries < QueryCount) {
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

    // Check if all queries executed; if not, run synchronously
    // (all NewOrders are already executed, so spawning childs doesn't make sense)
    int additionalQueries = QueryCount - executedQueries;

    while (additionalQueries-- > 0) {
      cout << "    Query result: " << lastNameOrderSum("BARBARBAR", &tpcc) << "." << endl;
    }

    t.stop();
    cout << " ✔  Done in " << t.seconds << " sec (" << NewOrderCount/t.seconds << " tps)." << endl;

    return 0;
  }
  catch (string msg) {
    cerr << " ✘ Exception thrown: " << msg << endl;
    return 1;
  }
}

uint64_t getTime() {
  return (uint64_t)clock();
}
