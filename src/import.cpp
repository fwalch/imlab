#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "import.h"
#include "timer.h"

using namespace std;

template<int C> void import(string path, Store* store) {
  ifstream file(path.c_str());
  string line;

  if (!file.is_open()) {
    throw "Data file '" + path + "' missing!";
  }

  while (getline(file, line).good()) {
    stringstream ss(line);
    string elem;

    int i = 0;
    string columns[C];
    while (getline(ss, elem, '|').good()) {
      columns[i++] = elem;
    }
    columns[i] = elem;

    store->add(columns);
  }

  file.close();
}

void importSampleData(string path, Tpce* store) {
  Timer t;
  t.start();
  cout << " ✱ Importing TPC-E sample data." << endl;

  cout << "    Importing customers..." << endl;
  import<24>(path + "/Customer.txt", &store->customers);

  cout << "    Importing account permissions..." << endl;
  import<5>(path + "/AccountPermission.txt", &store->accountPermissions);

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec." << endl;
}

void importSampleData(string path, Yago* store) {
  Timer t;
  t.start();
  cout << " ✱ Importing Yago facts." << endl;

  import<3>(path + "/yagoFacts.processed.tsv", &store->facts);

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec." << endl;
}

void importSampleData(string path, Tpcc* store) {
  Timer t;
  t.start();
  cout << " ✱ Importing TPC-C sample data." << endl;

  cout << "    Importing warehouses..." << endl;
  import<9>(path + "/tpcc_warehouse.tbl", &store->warehouses);

  cout << "    Importing districts..." << endl;
  import<11>(path + "/tpcc_district.tbl", &store->districts);

  cout << "    Importing customers..." << endl;
  import<21>(path + "/tpcc_customer.tbl", &store->customers);

  cout << "    Importing history..." << endl;
  import<8>(path + "/tpcc_history.tbl", &store->history);

  cout << "    Importing new orders..." << endl;
  import<3>(path + "/tpcc_neworder.tbl", &store->newOrders);

  cout << "    Importing orders..." << endl;
  import<8>(path + "/tpcc_order.tbl", &store->orders);

  cout << "    Importing order lines..." << endl;
  import<10>(path + "/tpcc_orderline.tbl", &store->orderLines);

  cout << "    Importing items..." << endl;
  import<5>(path + "/tpcc_item.tbl", &store->items);

  cout << "    Importing stock..." << endl;
  import<17>(path + "/tpcc_stock.tbl", &store->stock);

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec." << endl;
}

