#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "IAction.h"
#include <stack>

class Editor {
    public:
      static Editor& getInstance();
      void process(std::shared_ptr<IAction> action);
      std::shared_ptr<IAction> undo();
      std::shared_ptr<IAction> redo();
    private:
      Editor() = default;
      Editor(const Editor& other) = delete;
      Editor& operator=(const Editor& other) = delete;
      std::stack<std::shared_ptr<IAction>> stack_undo;
      std::stack<std::shared_ptr<IAction>> stack_redo;
};

#endif //EDITOR_HPP