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
      State currentState;
      std::vector<Tokenizer::SToken>& tokens_;
      SyntaxAnalyser(std::vector<Tokenizer::SToken> tokens);
      void CheckToken(const Tokenizer::SToken& token);
};

#endif //SYNTAX_ANALYSER_HPP