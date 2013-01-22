#include "command.h"

void Command::execute(int argc, char** argv) {
  for (int i = 0; i < argc; i++) {
    auto it = flags.find(argv[i]);
    if (it != flags.end()) {
      it->second.second = true;
    }
  }
}
