#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Slide.h"

class Document {
    public:
      Document();
      void AddSlide(std::shared_ptr<Slide>);
      void RemoveSlide();
    private:
      std::shared_ptr<Slide> slide;
      std::vector<std::shared_ptr<Slide>> slides;
};

#endif //DOCUMENT_HPP