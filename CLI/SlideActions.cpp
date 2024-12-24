#include "IAction.h" 

AddSlideAction::AddSlideAction(std::shared_ptr<Slide> slide) : mpSlide(slide) {}

std::shared_ptr<IAction> AddSlideAction::Do() {
    Application::getInstance().document->AddSlide(mpSlide, mpSlide->id);
    std::shared_ptr<IAction> action = std::make_shared<RemoveSlideAction>(mpSlide);
    return action;
}

RemoveSlideAction::RemoveSlideAction(std::shared_ptr<Slide> slide) : mpSlide(slide) {}

std::shared_ptr<IAction> RemoveSlideAction::Do() {
    Application::getInstance().document->RemoveSlide(mpSlide->id);
    std::shared_ptr<IAction> action = std::make_shared<AddSlideAction>(mpSlide);
    return action;
}








