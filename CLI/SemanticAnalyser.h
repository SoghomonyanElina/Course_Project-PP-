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
      SemanticAnalyser(SyntaxAnalyser::SCommand& command);
      bool CheckCommand();
    private:
      std::map<std::string, std::map<std::string, Args>> cmd;
      bool isCmdSingle();
      bool isCmdName();
      bool isOption();
      bool isShape();
      bool isColor();
      bool CheckPosition();
      bool CheckID();
};

#endif //SEMANTIC_ANALYSER_HPP