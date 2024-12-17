#include "ICommand.h"

AddShapeCommand::AddShapeCommand(std::vector<std::string>& args, std::shared_ptr<Editor> editor) : editor_(editor) {
    if(args[3] == "circle") {
        type = Type::circle;
    }
    else if(args[3] == "rectangle") {
        type = Type::rectangle;
    }
    else if(args[3] == "triangle") {
        type = Type::triangle;
    }
    else if(args[3] == "parallelogram") {
        type = Type::parallelogram;
    }
    else if(args[3] == "arrow") {
        type = Type::arrow;
    }
    else if(args[3] == "line") {
        type = Type::line;
    }
    geometry.x_ = std::stod(args[5]);
    geometry.y_ = std::stod(args[6]);
    attribute.color_ = args[args.size() - 1];
}

void AddShapeCommand::execute() {
    std::shared_ptr<Item> newItem = std::make_shared<Item>();
    std::shared_ptr<IAction> action = std::make_shared<AddShapeAction>(newItem, geometry, attribute, type);
    Editor::process;
}

RemoveShapeCommand::RemoveShapeCommand(std::vector<std::string>& args, std::shared_ptr<Editor> editor) : editor_(editor) {

}

void RemoveShapeCommand::execute() {

}