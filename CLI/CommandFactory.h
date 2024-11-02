#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include "ICommand.h"
#include "SyntaxAnalyser.h"


class CommandFactory {
    public:
      std::string cmd_name;
      std::vector<std::string> Args;
      std::unique_ptr<ICommand> CreateCommand();

};

#endif //COMMAND_FACTORY_HPP