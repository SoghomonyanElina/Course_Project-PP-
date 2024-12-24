#ifndef IACTION_HPP
#define IACTION_HPP

#include "../Application/Application.h"
#include "../Document/Document.h"
#include <memory>

class IAction {
    public:
      virtual std::shared_ptr<IAction> Do() = 0;
      virtual ~IAction() = default;
};

class AddShapeAction : public IAction {
    private:
      std::shared_ptr<Slide> mpSlide;
    public:
      std::shared_ptr<IAction> Do() override;
};

class RemoveShape : public IAction {
    private:
      std::shared_ptr<Slide> mpSlide;
    public:
      std::shared_ptr<IAction> Do() override;
};

class AddSlideAction : public IAction {
    private:
      std::shared_ptr<Slide> mpSlide;
    public:
      AddSlideAction(std::shared_ptr<Slide> slide);
      std::shared_ptr<IAction> Do() override;
};

class RemoveSlideAction : public IAction {
    private:
      std::shared_ptr<Slide> mpSlide;
    public:
      RemoveSlideAction(std::shared_ptr<Slide> slide);
      std::shared_ptr<IAction> Do() override;
};

#endif //IACTION_HPP