#include <ctime>
#include "tpcc_command.h"
#include "../import.h"
#include "../timer.h"
#include "../oltp.h"
#include "../olap.h"
#include "../../gen/tpcc/lastname_order_sum_query.h"
#include "../../gen/tpcc/tax_query.h"

using namespace std;

uint64_t getTime();

void TpccCommand::execute(int argc, char** argv) {
  Command::execute(argc, argv);

  importSampleData("data", &tpcc);
  stopAfterExecution();

  if (flags[DeliveryFlag].second) {
    executeDeliveryTransactions();
    stopAfterExecution();
  }

  if (flags[NewOrderFlag].second) {
    executeNewOrderTransactions();
    stopAfterExecution();
  }

  if (flags[QueryFlag].second) {
    executeQueries();
    stopAfterExecution();
  }
}

void TpccCommand::executeDeliveryTransactions() {
  Timer t;
  t.start();
  cout << " ✱ Running " << DeliveryCount << " Delivery transactions." << endl;

  for (int i = 0; i < DeliveryCount; i++) {
    deliveryRandom(getTime(), urand(1, Warehouses), &tpcc);
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << DeliveryCount/t.seconds << " tps)." << endl;
}

void TpccCommand::executeQueries() {
  Timer t;
  t.start();
  cout << " ✱ Running " << 2 * QueryCount << " queries." << endl;

  // Query execution will print output
  for (int i = 0; i < QueryCount; i++) {
    cout << " 1" << endl;
    cout << "sum" << endl;
    // select sum(ol_quantity * ol_amount)
    // from customer, "order", orderline
    // where o_c_id = c_id
    // and o_w_id = ol_w_id
    // and o_d_id = ol_d_id
    // and o_id = ol_o_id
    // and c_last = 'BARBARBAR'
    tpcc::lastnameOrderSumQuery(&tpcc);

    cout << " 2" << endl;
    cout << "w_name|d_name|d_tax" << endl;
    // select w_name, d_name, d_tax
    // from warehouse, district
    // where w_id = d_w_id
    // and w_id = 1
    tpcc::taxQuery(&tpcc);
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << QueryCount/t.seconds << " qps)." << endl;
}

void TpccCommand::executeNewOrderTransactions() {
  Timer t;
  t.start();
  cout << " ✱ Running " << NewOrderCount << " NewOrder transactions." << endl;

  for (int i = 0; i < NewOrderCount; i++) {
    newOrderRandom(getTime(), urand(1, Warehouses), &tpcc);
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << NewOrderCount/t.seconds << " tps)." << endl;
}


uint64_t getTime() {
  return (uint64_t)clock();
}
