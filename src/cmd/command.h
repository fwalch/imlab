#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

class Command {
  private:
    const char* WaitFlag = "-w";
    const char* WaitFlagDesc = "Wait for user input after each completed action";

  protected:
    std::unordered_map<std::string, std::pair<const char*, bool>> flags;

    inline void stopAfterExecution() {
      if (flags[WaitFlag].second) {
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.get();
      }
    }

  public:
    virtual ~Command() { }
    virtual void initialize() {
      flags[WaitFlag] = std::make_pair(WaitFlagDesc, false);
    }

    virtual void execute(int argc, char** argv);

    void help(std::function<void (std::string)> helpAction) {
      for (auto it : flags) {
        helpAction(it.first + "  " + it.second.first);
      }
    }
};

#endif
