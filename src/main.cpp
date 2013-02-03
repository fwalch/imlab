#include "cmd/command_executor.h"

int main(int argc, char** argv) {
  CommandExecutor executor;
  return executor.execute(argc-1, argv+1);
}
