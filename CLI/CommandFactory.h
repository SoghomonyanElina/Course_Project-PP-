#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include "ICommand.h"
#include "SyntaxAnalyser.h"
#include <map>
#include <memory>

class CommandFactory {
    public:
      CommandFactory(SyntaxAnalyser::SCommand& command);
      std::unique_ptr<ICommand> CreateCommand();
    private:
      std::map<std::string, std::function<std::unique_ptr<ICommand>()>> commandMap;
      SyntaxAnalyser::SCommand& command_;
};

#endif //COMMAND_FACTORY_HPP