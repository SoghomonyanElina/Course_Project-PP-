#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "IAction.h"
#include <stack>

class Editor {
    public:
      void process(std::shared_ptr<IAction> action);
      void undo();
      void redo();
    private:
      std::stack<std::shared_ptr<IAction>> stack_undo;
       std::stack<std::shared_ptr<IAction>> stack_redo;
};

#endif //EDITOR_HPP