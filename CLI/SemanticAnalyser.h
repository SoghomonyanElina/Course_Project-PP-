#ifndef SEMANTIC_ANALYSER_HPP
#define SEMANTIC_ANALYSER_HPP

#include "SyntaxAnalyser.h"
#include "ICommand.h"
#include "CommandFactory.h"
#include <exception>
#include <map>
#include <memory>
#include <variant>

using Args = std::variant<std::string, int, std::pair<float, float>>;

class SemanticAnalyser {
    public:
      SyntaxAnalyser::SCommand& command_;
      std::map<std::string, std::map<std::string, Args>> cmd;
      SemanticAnalyser(SyntaxAnalyser::SCommand& command);
      bool CheckCommand();
      int CmdNameSize();
      //std::unique_ptr<ICommand> CreateCommand();
    private:
      bool isCmdName();
      bool isOption();
      bool isShape();
      bool isColor();

};

#endif //SEMANTIC_ANALYSER_HPP