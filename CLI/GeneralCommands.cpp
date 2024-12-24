#include "ICommand.h"

void ExitCommand::execute() {

}

void HelpCommand::execute() {

}

void UndoCommand::execute() {
    Application::getInstance().editor->undo();
}

void RedoCommand::execute() {
    Application::getInstance().editor->redo();
}




