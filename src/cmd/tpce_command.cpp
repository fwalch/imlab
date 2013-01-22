#include "tpce_command.h"
#include "../import.h"

void TpceCommand::execute(int argc, char** argv) {
  Command::execute(argc, argv);

  importSampleData("data", &tpce);
  stopAfterExecution();
}
