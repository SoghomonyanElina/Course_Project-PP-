#include "Controller.h"

Controller::Controller() {
    parser = std::make_unique<Parser>(std::cin);
}
void Controller::Start() {
    std::unique_ptr<ICommand> cmd = parser->Parse();
    cmd->execute();
}