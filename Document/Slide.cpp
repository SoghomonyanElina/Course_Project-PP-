#include "Slide.h"

void Slide::addItem() {
    items.push_back(item);
}

std::shared_ptr<Item> Slide::GetItem() {
    return item;
}



