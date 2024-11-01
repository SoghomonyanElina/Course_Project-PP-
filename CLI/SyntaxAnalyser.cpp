#include "SyntaxAnalyser.h"

SyntaxAnalyser::SyntaxAnalyser(/*std::vector<Tokenizer::SToken> tokens*/) {
  currentState = State::Start;
}

void SyntaxAnalyser::CheckToken(const Tokenizer::SToken& token) {
  if(currentState == State::Error) {
    return;
  }
  switch(currentState) {
    case State::Start:
      if(token._type == Tokenizer::SToken::EType::Word) {
        currentState = State::Command;
        command.CmdName += token._value + ' ';
        std::cout << "Pushed_name" << std::endl;
      }
      else {
        currentState = State::Error;
      }
      break;
    case State::Command:
      if(token._type == Tokenizer::SToken::EType::Word) {
        currentState = State::Command;
        command.CmdName += token._value;
        std::cout << "Pushed_name" << std::endl;
      } 
      else if(token._type == Tokenizer::SToken::EType::Option) {
        currentState = State::Argument;
        command.ArgList.push_back(token._value);
        std::cout << "Pushed_args" << std::endl;
      }
      else {
        currentState = State::Error;
      }
      break;
    case State::Argument:
      if(token._type == Tokenizer::SToken::EType::Option || token._type == Tokenizer::SToken::EType::Value) {
        currentState = State::Argument;
        command.ArgList.push_back(token._value);
        std::cout << "Pushed_args" << std::endl;
      }
      else {
        currentState = State::Error;
      }
      break;
  }
}