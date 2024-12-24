#include "ICommand.h"

AddShapeCommand::AddShapeCommand(std::vector<std::string>& args) {
    if(args[3] == "circle") {
        Application::getInstance().document->slide->item->type_ = Type::circle;
    }
    else if(args[3] == "rectangle") {
        Application::getInstance().document->slide->item->type_ = Type::rectangle;
    }
    else if(args[3] == "triangle") {
        Application::getInstance().document->slide->item->type_ = Type::triangle;
    }
    else if(args[3] == "parallelogram") {
        Application::getInstance().document->slide->item->type_ = Type::parallelogram;
    }
    else if(args[3] == "arrow") {
        Application::getInstance().document->slide->item->type_ = Type::arrow;
    }
    else if(args[3] == "line") {
        Application::getInstance().document->slide->item->type_ = Type::line;
    }
    Application::getInstance().document->slide->item->geometry_.x_ = std::stod(args[5]);
    Application::getInstance().document->slide->item->geometry_.y_ = std::stod(args[6]);
    Application::getInstance().document->slide->item->attribute_.color_ = args[args.size() - 1];
}

void AddShapeCommand::execute() {
    std::shared_ptr<Item> newItem = std::make_shared<Item>();
    std::shared_ptr<IAction> action = std::make_shared<AddShapeAction>(newItem);
    Application::getInstance().editor->process(action);
}

RemoveShapeCommand::RemoveShapeCommand(std::vector<std::string>& args) {

}

void RemoveShapeCommand::execute() {

}