#ifndef _TPCC_COMMAND_H_
#define _TPCC_COMMAND_H_

#include <iostream>
#include "command.h"
#include "../tpcc.h"

class TpccCommand : public Command {
  private:
    Tpcc tpcc;
    const int DeliveryCount = 1E6;
    const char* DeliveryFlag = "-d";
    const char* DeliveryFlagDesc = "Execute Delivery transaction";

    const int QueryCount = 1E3;
    const char* QueryFlag = "-q";
    const char* QueryFlagDesc = "Execute generated queries";

    const int NewOrderCount = 1E6;
    const char* NewOrderFlag = "-n";
    const char* NewOrderFlagDesc = "Execute NewOrder transactions";

    void executeDeliveryTransactions();
    void executeNewOrderTransactions();
    void executeQueries();

  public:
    void initialize() {
      Command::initialize();

      flags[DeliveryFlag] = std::make_pair(DeliveryFlagDesc, false);
      flags[NewOrderFlag] = std::make_pair(NewOrderFlagDesc, false);
      flags[QueryFlag] = std::make_pair(QueryFlagDesc, false);
    }
    void execute(int argc, char** argv);
};

#endif
