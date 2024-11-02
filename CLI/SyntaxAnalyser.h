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
        std::string CmdName;
        std::vector<std::string> ArgList;
      };
      State currentState;
      SCommand command_;
      SyntaxAnalyser();
      void CheckToken(const Tokenizer::SToken& token);
      const SCommand& GetCommand();
};

#endif //SYNTAX_ANALYSER_HPP