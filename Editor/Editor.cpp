#include "Editor.h"

Editor& Editor::getInstance() {
    static Editor editor;
    return editor;
}

void Editor::process(std::shared_ptr<IAction> action) {
    stack_undo.push(action->Do());
    stack_redo.clear();
}

void Editor::undo() {
    stack_redo.push(stack_undo.top()->Do());
    stack_undo.pop();
}

void Editor::redo() {
    stack_undo.push(stack_redo.top()->Do());
    stack_redo.pop();
}

