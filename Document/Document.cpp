#include "Document.h"

Document::Document() {
    slide = std::make_shared<Slide>();
    slides.push_back(slide);
}

void Document::AddSlide(std::shared_ptr<Slide> slide, int id) {
    slides.insert(slide, id);
}

void Document::RemoveSlide(int id) {
    slides.erase(slides.begin() + id);
}