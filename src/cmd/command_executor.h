#ifndef _COMMAND_EXECUTOR_H_
#define _COMMAND_EXECUTOR_H_

#include <iostream>
#include <unordered_map>
#include "tpcc_command.h"
#include "tpce_command.h"
#include "yago_command.h"

class CommandExecutor {
  private:
    std::unordered_map<std::string, Command*> commands = {
      { "tpcc", new TpccCommand() },
      { "tpce", new TpceCommand() },
      { "yago", new YagoCommand() },
    };

    void showHelp() {
      std::cout << "fakedb <command> [<args>]" << std::endl;
      std::cout << std::endl;
      std::cout << "Each command will import sample data as a first step. ";
      std::cout << "Additional steps will be executed according to passed arguments." << std::endl;
      std::cout << std::endl;
      std::cout << "Available Commands:" << std::endl;
      for (auto it : commands) {
        std::cout << "   " << it.first << std::endl;
        it.second->help([] (std::string text) {
            std::cout << "      " << text << std::endl;
        });
      }
    }
  public:
    ~CommandExecutor() {
      for (auto it : commands) {
        delete it.second;
      }
    }

    void initialize() {
      for (auto it : commands) {
        it.second->initialize();
      }
    }

    int execute(int argc, char** argv) {
      try {
        if (argc > 0) {
          auto it = commands.find(argv[0]);
          if (it != commands.end()) {
            it->second->execute(argc-1, argv+1);
            return 0;
          }
        }

        showHelp();
        return 2;
      }
      catch (std::string msg) {
        std::cerr << " ✘ Exception thrown: " << msg << std::endl;
        return 1;
      }
    }
};

#endif
