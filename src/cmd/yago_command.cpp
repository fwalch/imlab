#include "yago_command.h"
#include "../import.h"

void YagoCommand::execute(int argc, char** argv) {
  Command::execute(argc, argv);

  importSampleData("data", &yago);
  stopAfterExecution();
}

