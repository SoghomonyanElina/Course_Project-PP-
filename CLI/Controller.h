#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "Parser.h"

class Controller {
    public:
      Controller() = default;
      void Start();
    private:
      std::unique_ptr<Parser> parser;
};

#endif //CONTROLLER_HPP