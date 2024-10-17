#include "SyntaxAnalyser.h"

SyntaxAnalyser::SyntaxAnalyser(std::vector<Tokenizer::SToken> tokens) : tokens_(tokens) {
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
            tokens_.push_back(token);
          }
          else {
            currentState = State::Error;
          }
          break;
        case State::Command:
          if(token._type == Tokenizer::SToken::EType::Word) {
            currentState = State::Command;
            tokens_.push_back(token);
          } 
          else if(token._type == Tokenizer::SToken::EType::Option) {
            currentState = State::Argument;
            tokens_.push_back(token);
          }
          else {
            currentState = State::Error;
          }
          break;
        case State::Argument:
          if(token._type == Tokenizer::SToken::EType::Option || token._type == Tokenizer::SToken::EType::Value) {
            currentState = State::Argument;
            tokens_.push_back(token);
          }
          else {
            currentState = State::Error;
          }
          break;
    }
}