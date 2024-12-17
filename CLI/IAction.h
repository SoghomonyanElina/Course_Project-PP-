#ifndef IACTION_HPP
#define IACTION_HPP

#include <memory>
#include "../Document/Document.h"

class IAction {
    public:
      virtual std::shared_ptr<IAction> Do() = 0;
      virtual ~IAction() = default;
};

class AddShapeAction : public IAction {
    private:
      std::shared_ptr<Slide> mp_slide;
    public:
      std::shared_ptr<IAction> Do() override;
};

class RemoveShape : public IAction {
    private:
      std::shared_ptr<Slide> mp_slide;
    public:
     std::shared_ptr<IAction> Do() override;
};

class AddSlideAction : public IAction {
    private:
      std::shared_ptr<Slide> mp_slide;
    public:
     std::shared_ptr<IAction> Do() override;
};

class RemoveSlideAction : public IAction {
    private:
      std::shared_ptr<Slide> mp_slide;
    public:
     std::shared_ptr<IAction> Do() override;
};

#endif //IACTION_HPP