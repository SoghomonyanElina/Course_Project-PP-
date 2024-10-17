#include "Tokenizer.h"

bool Tokenizer::isWord(const std::string& token) {
    bool result = !token.empty() && std::all_of(token.begin(), token.end(), [](unsigned char it) {
        return std::isalpha(it);
      });
    return result;
}

bool Tokenizer::isOption(const std::string& token) {
    bool result = token[0] == '-' && token.size() > 1 && isWord(token.substr(1));
    return result;
}

bool Tokenizer::isValue(const std::string& token) {
    bool result = isNumber(token) || (hasPrecedingSpace(token) && isWord(token) && isOption(previousToken._value));
    return result;
}

bool Tokenizer::isNumber(const std::string& token) {
    if(token[0] == '-') {
        return false;
    }
    //for double
    double digit;
    std::istringstream _token(token);
    if(!token.empty() && _token >> digit && _token.eof()) {
        return true;
    }
    //for int
    else {
        if(!token.empty() && std::all_of(token.begin(), token.end(), [](unsigned char it) {
            return std::isdigit(it);
        })) {
            return true;
        }
    }
    return false;
}

bool Tokenizer::hasPrecedingSpace(/*const std::stringstream& m_cmd*/ const std::string& token) {
    std::string command = cmd_.str();
    size_t position = command.find(token);
    if(position != std::string::npos && position > 0) {
        return command[position - 1] == ' ';
    }
    return false;
}

bool Tokenizer::isEnd() {
    std::string command = cmd_.str();
    return std::isspace(command[command.size() - 1]);
}

Tokenizer::SToken& Tokenizer::GetToken() {
    std::string command_;
    previousToken = currentToken;
    if(cmd_ >> command_) {
        if(isValue(command_)) {
            currentToken._type = SToken::EType::Value;
            std::cout << "Recognized as Value: " << command_ << std::endl;
        }
        else if(isWord(command_)) {
            currentToken._type = SToken::EType::Word;
            std::cout << "Recognized as Word: " << command_ << std::endl;
        }
        else if(isOption(command_)) {
            currentToken._type = SToken::EType::Option;
            std::cout << "Recognized as Option: " << command_ << std::endl;
        }
        else {
            if(isEnd()) {
                currentToken._type = SToken::EType::End;
            }
        }
        currentToken._value = command_;
        return currentToken;
    }
    currentToken._type = SToken::EType::End;
    currentToken._value = " ";
    return currentToken;
}


