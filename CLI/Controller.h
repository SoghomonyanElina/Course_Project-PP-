#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "Parser.h"

class Controller {
    public:
      Controller();
      void Start();
    private:
      std::unique_ptr<Parser> parser;
    // I will continue.
};

#endif //CONTROLLER_HPP