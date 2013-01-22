#ifndef _TPCE_COMMAND_H_
#define _TPCE_COMMAND_H_

#include <iostream>
#include "command.h"
#include "../tpce.h"

class TpceCommand : public Command {
  private:
    Tpce tpce;

  public:
    void execute(int argc, char** argv);
};

#endif
