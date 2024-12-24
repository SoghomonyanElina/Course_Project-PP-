#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

#include "IAction.h"
#include "../Application/Application.h"
#include "../Editor/Editor.h"
#include <string>
#include <vector>

class ICommand {
  public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
};

class AddSlideCommand : public ICommand {
  public:
    AddSlideCommand(std::vector<std::string>& args);
    void execute() override;
  private:
    std::shared_ptr<Slide> slide_;
};

class RemoveSlideCommand : public ICommand {
  public:
    RemoveSlideCommand(std::vector<std::string>& args);
    void execute() override;
  private:
    std::shared_ptr<Slide> slide_;
};

class AddShapeCommand : public ICommand {
  public:
    AddShapeCommand(std::vector<std::string>& args);
    void execute() override;
    /*Geometry geometry;
    Attribute attribute;
    Type type;*/
};

class RemoveShapeCommand : public ICommand {
  public:
    RemoveShapeCommand(std::vector<std::string>& args);
    void execute() override;
};

class ExitCommand : public ICommand {
  public:
    ExitCommand();
    void execute() override;
};

class HelpCommand : public ICommand {
  public:
    HelpCommand();
    void execute() override;
};

class UndoCommand : public ICommand {
  public:
    UndoCommand();
    void execute() override;
};

class RedoCommand : public ICommand {
  public:
    RedoCommand();
    void execute() override;
};

#endif //ICOMMAND_HPP