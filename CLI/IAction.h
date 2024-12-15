#ifndef IACTION_HPP
#define IACTION_HPP

#include <memory>
#include "Document.h"

class IAction {
    public:
      virtual void Do() = 0;
      virtual ~IAction() = default;
};

#endif //IACTION_HPP