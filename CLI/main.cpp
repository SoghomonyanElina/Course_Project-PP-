#include "Tokenizer.h"
int main() {
    std::string input;
    getline(std::cin, input);
    Tokenizer tokenizer(input);
    while(tokenizer.GetToken()._type != Tokenizer::SToken::EType::End) {
        std::cout << static_cast<int>(tokenizer.currentToken._type) << ' ' << tokenizer.currentToken._value << std::endl;
    }
}