#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Item.h"
#include <vector>

class Slide {
    public:
      Slide() = default;
      void addItem();
      std::shared_ptr<Item> GetItem();
    private:
      std::shared_ptr<Item> item;
      std::vector<std::shared_ptr<Item>> items;
};

#endif //SLIDE_HPP
