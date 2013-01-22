#ifndef _YAGO_COMMAND_H_
#define _YAGO_COMMAND_H_

#include <iostream>
#include "command.h"
#include "../yago.h"

class YagoCommand : public Command {
  private:
    Yago yago;

  public:
    void execute(int argc, char** argv);
};

#endif
