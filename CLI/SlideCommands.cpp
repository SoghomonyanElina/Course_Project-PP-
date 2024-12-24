#include "ICommand.h"

AddSlideCommand::AddSlideCommand(std::vector<std::string>& args) {
    slide_ = std::make_shared<Slide>();
    slide_->id = args[3]; 
}

void AddSlideCommand::execute() {
    //std::shared_ptr<Slide> newSlide = std::make_shared<Slide>();
    std::shared_ptr<IAction> action = std::make_shared<AddSlideAction>(slide_);
    Application::getInstance().editor->process(action);
}

RemoveSlideCommand::RemoveSlideCommand(std::vector<std::string>& args) {
    slide_->id = args[3];
}

void RemoveSlideCommand::execute() {
    std::shared_ptr<IAction> action = std::make_shared<RemoveSlideAction>(slide_);
    Application::getInstance().editor->process(action);
}