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
      SyntaxAnalyser(Tokenizer* obj);
      void ParseToken();
    private:
      Tokenizer* m_obj;
      State currentState;
      State nextState;
};

#endif //SYNTAX_ANALYSER_HPP