#include "Parser.h"

Parser::Parser(std::string& cmd) : m_cmd(cmd) {
    tokenizer_ = std::make_unique<Tokenizer>(m_cmd);
    analyser_ = std::make_unique<SyntaxAnalyser>(tokens);
    creator_ = std::make_unique<CommandCreator>();
}

std::unique_ptr<ICommand> Parser::Parse() {
    while(tokenizer_->GetToken()._type != Tokenizer::SToken::EType::End) {
        analyser_->CheckToken(tokenizer_->currentToken);
        if(analyser_->currentState == SyntaxAnalyser::State::Error) {
            break;
        }
    }
    if(analyser_->currentState != SyntaxAnalyser::State::Error) {
        analyser_->currentState = SyntaxAnalyser::State::Finish;
    }
    return creator_->Create();
}