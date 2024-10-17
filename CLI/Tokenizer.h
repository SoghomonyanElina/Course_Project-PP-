#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include <algorithm>
#include <iostream>
#include <sstream>

class Tokenizer {
  public:
    struct SToken {
      enum class EType {
        Word,
        Option,
        Value,
        End
      };
      EType _type;
      std::string _value;
    };
    SToken currentToken;
    SToken previousToken;
    Tokenizer(std::stringstream& cmd) : cmd_(cmd) {};
    SToken& GetToken();
  private: 
    std::stringstream& cmd_;
    bool isNumber(const std::string& token);
    bool hasPrecedingSpace(/*const std::stringstream& m_cmd*/ const std::string& token);
    bool isWord(const std::string& token);
    bool isOption(const std::string& token);
    bool isValue(const std::string& token);
    bool isEnd();
};

#endif //TOKENIZER_HPP
