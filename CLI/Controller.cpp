#include "Controller.h"

/*Controller::Controller() {
    parser = std::make_unique<Parser>(std::cin);
}*/
void Controller::Start() {
    parser = std::make_unique<Parser>(std::cin);
    std::unique_ptr<ICommand> cmd = parser->Parse();
    if(cmd) {
        cmd->execute();
    }
}