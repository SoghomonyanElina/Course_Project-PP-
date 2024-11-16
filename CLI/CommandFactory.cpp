#include "CommandFactory.h"

CommandFactory::CommandFactory(SyntaxAnalyser::SCommand& command) : command_(command) {
    commandMap = {
        {"add slide", [this]() { return std::make_unique<AddSlideCommand>(command_.ArgList); }},
        {"remove slide", [this]() { return std::make_unique<RemoveShapeCommand>(command_.ArgList); }},
        {"add shape", [this]() { return std::make_unique<AddShapeCommand>(command_.ArgList); }},
        {"remove shape", [this]() { return std::make_unique<RemoveShapeCommand>(command_.ArgList); }},
        {"help", []() { return std::make_unique<HelpCommand>(); }},
        {"exit", []() { return std::make_unique<ExitCommand>(); }},
        {"undo", []() { return std::make_unique<UndoCommand>(); }},
        {"redo", []() { return std::make_unique<RedoCommand>(); }}  
    };
}

std::unique_ptr<ICommand> CommandFactory::CreateCommand() {
    auto it = commandMap.find(command_.CmdName);
    if(it != commandMap.end()) {
        return it->second();
    }
    throw std::runtime_error("Unknown command name: " + command_.CmdName);
}


