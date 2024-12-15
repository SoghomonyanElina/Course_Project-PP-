#include "Document.h"

Document::Document() {
    slide = std::make_shared<Slide>();
    slides.push_back(slide);
}

void Document::AddSlide(std::shared_ptr<Slide> slide) {
    slides.push_back(slide);
}