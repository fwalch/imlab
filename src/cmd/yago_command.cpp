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
  cout << " ✱ Querying websites of all women." << endl;

  size_t count = yago.queryWebsitesOfAllWomen();

  t.stop();
  cout << " ✔  Done in " << t.seconds << " sec; found " << count << " websites." << endl;
}
