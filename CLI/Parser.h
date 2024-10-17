#ifndef PARSER_HPP
#define PARSER_HPP
#include <memory>
#include <vector>
#include "Tokenizer.h"
#include "SyntaxAnalyser.h"
#include "ICommand.h"
#include "CommandCreator.h"

class Parser {
    public:
       std::stringstream m_cmd;
       std::vector<Tokenizer::SToken> tokens;
       Parser(std::string& cmd);
       ~Parser() = default;
       std::unique_ptr<ICommand> Parse();
    private:
      std::unique_ptr<Tokenizer> tokenizer_;
      std::unique_ptr<SyntaxAnalyser> analyser_;
      std::unique_ptr<CommandCreator> creator_;
};

#endif //PARSER_HPP