#include "SyntaxAnalyser.h"

SyntaxAnalyser::SyntaxAnalyser(Tokenizer* obj) : currentState(State::Start), m_obj(obj) {}
void SyntaxAnalyser::ParseToken() {
    while(m_obj->GetToken()._type != Tokenizer::SToken::EType::End) {
        

    }

}

