#ifndef _YAGO_COMMAND_H_
#define _YAGO_COMMAND_H_

#include <iostream>
#include "command.h"
#include "../yago.h"

class YagoCommand : public Command {
  private:
    Yago yago;

    const char* QueryFlagDesc = "Execute website query";
    const char* QueryFlag = "-q";

    void executeWebsiteQuery();

  public:
    YagoCommand() {
      Command();

      flags[QueryFlag] = std::make_pair(QueryFlagDesc, false);
    }
    void execute(int argc, char** argv);
};

#endif
