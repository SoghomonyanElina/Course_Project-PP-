#include "Tokenizer.h"

bool Tokenizer::isWord(const std::string& token) {
    return !token.empty() && !hasPrecedingSpace(m_cmd, token) && std::all_of(token.begin(), token.end(), [](unsigned char it) {
        return std::isalpha(it);
    });
}

bool Tokenizer::isOption(const std::string& token) {
    return token.size() > 1 && token[0] == '-' && isWord(token.substr(1));
}

bool Tokenizer::isValue(const std::string& token) {
    return isNumber(token) || (hasPrecedingSpace(m_cmd, token) && isWord(token));
}

bool Tokenizer::isNumber(const std::string& token) {
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

bool Tokenizer::hasPrecedingSpace(const std::stringstream& m_cmd, const std::string& token) {
    std::string command = m_cmd.str();
    size_t position = command.find(token);
    if(position != std::string::npos && position > 0) {
        return command[position - 1] == ' ';
    }
    return false;
}

bool Tokenizer::isEnd(const std::stringstream& cmd) {
    std::string command = cmd.str();
    return std::isspace(command[command.size() - 1]);
}

Tokenizer::SToken& Tokenizer::GetToken() {
    std::string command_;
    if(m_cmd >> command_) {
        if(isWord(command_)) {
            currentToken._type = SToken::EType::Word;
        }
        else if(isOption(command_)) {
            currentToken._type = SToken::EType::Option;
        }
        else if(isValue(command_)) {
            currentToken._type = SToken::EType::Value;
        }
        else {
            if(isEnd(m_cmd)) {
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


