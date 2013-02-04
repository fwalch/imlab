#include "yago_command.h"
#include "../import.h"
#include "../timer.h"
#include <iostream>

using namespace std;

void YagoCommand::execute(int argc, char** argv) {
  Command::execute(argc, argv);

  importSampleData("data", &yago);
  stopAfterExecution();

  if (flags[QueryFlag].second) {
    executeWebsiteQuery();
    stopAfterExecution();
  }
}

void YagoCommand::executeWebsiteQuery() {
  Timer t;
  t.start();
  cout << " ✱ Running " << QueryCount << " website queries." << endl;

  for (int i = 0; i < QueryCount; i++) {
    cout << "Found " << yago.queryWebsitesOfAllWomen() << " websites." << endl;
  }

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec (" << QueryCount/t.seconds << " qps)." << endl;
}
