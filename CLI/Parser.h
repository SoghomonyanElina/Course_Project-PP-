#ifndef PARSER_HPP
#define PARSER_HPP
#include <memory>
#include <vector>
#include "Tokenizer.h"
#include "SyntaxAnalyser.h"
#include "SemanticAnalyser.h"
#include "CommandFactory.h"

class Parser {
   public:
      std::istream& m_cmd;
      std::unique_ptr<CommandFactory> factory_;
      //SyntaxAnalyser::SCommand command;
      Parser(std::istream& cmd);
      ~Parser() = default;
      std::unique_ptr<ICommand> Parse();
   private:
      std::unique_ptr<Tokenizer> tokenizer_;
      std::unique_ptr<SyntaxAnalyser> analyser_;
      std::unique_ptr<SemanticAnalyser> semanalyser_;
};

#endif //PARSER_HPP