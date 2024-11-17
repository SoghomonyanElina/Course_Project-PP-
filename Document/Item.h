#ifndef ITEM_HPP
#define ITEM_HPP

#include "Attribute.hpp"
#include "Geometry.hpp"
#include "Type.hpp"

class Item {
    public:
      Item();
    private:
      Attribute attribute;
      Geometry geometry;
      Type type;
};

#endif //ITEM_HPP