#include "cmd/command_executor.h"

int main(int argc, char** argv) {
  CommandExecutor executor;
  executor.initialize();
  return executor.execute(argc-1, argv+1);
}
