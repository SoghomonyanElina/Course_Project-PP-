#ifndef SYNTAX_ANALYSER_HPP
#define SYNTAX_ANALYSER_HPP
#include "Tokenizer.h"

class SyntaxAnalyser {
    public:
      enum class State {
        Start,
        Command,
        Argument,
        Finish,
        Error
      };
      struct SCommand {
        //std::vector<std::string> CmdName;
        std::string CmdName;
        std::vector<std::string> ArgList;
      };
      State currentState;
      SCommand command;
      //std::vector<Tokenizer::SToken>& tokens_;
      SyntaxAnalyser(/*std::vector<Tokenizer::SToken> tokens*/);
      void CheckToken(const Tokenizer::SToken& token);
};

#endif //SYNTAX_ANALYSER_HPP