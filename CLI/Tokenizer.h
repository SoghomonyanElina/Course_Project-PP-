#ifndef TOKENIZER_HPP
#define TOKENIZR_HPP
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
    Tokenizer(const std::string& cmd) : m_cmd(cmd) {};
    SToken& GetToken();
  private: 
    std::stringstream m_cmd;
    bool isNumber(const std::string& token);
    bool hasPrecedingSpace(const std::stringstream& m_cmd, const std::string& token);
    bool isWord(const std::string& token);
    bool isOption(const std::string& token);
    bool isValue(const std::string& token);
    bool isEnd(const std::stringstream& m_cmd);
};

#endif //TOKENIZER_HPP
