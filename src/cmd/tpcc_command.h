#ifndef _TPCC_COMMAND_H_
#define _TPCC_COMMAND_H_

#include <iostream>
#include "command.h"
#include "../tpcc.h"

class TpccCommand : public Command {
  private:
    Tpcc tpcc;

    const char* DeliveryFlagDesc = "Execute Delivery transaction";
    const char* QueryFlagDesc = "Execute generated queries";
    const char* NewOrderFlagDesc = "Execute NewOrder transactions";

    const char* DeliveryFlag = "-d";
    const char* QueryFlag = "-q";
    const char* NewOrderFlag = "-n";

    const long DeliveryCount = 1E6;
    const int QueryCount = 1E3;
    const int NewOrderCount = 1E6;

    void executeDeliveryTransactions();
    void executeNewOrderTransactions();
    void executeQueries();

  public:
    TpccCommand() {
      Command();

      flags[DeliveryFlag] = std::make_pair(DeliveryFlagDesc, false);
      flags[NewOrderFlag] = std::make_pair(NewOrderFlagDesc, false);
      flags[QueryFlag] = std::make_pair(QueryFlagDesc, false);
    }
    void execute(int argc, char** argv);
};

#endif
