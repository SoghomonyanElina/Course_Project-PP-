#ifndef ITEM_HPP
#define ITEM_HPP

#include "Attribute.h"
#include "Geometry.h"
#include "Type.h"
#include <memory>

class Item {
    public:
      Item() = default;
      void SetGeometry(Geometry& geometry);
      Geometry& GetGeometry();
      void SetAttribute(Attribute& attribute);
      Attribute& GetAttribute();
      void SetType(Type& type);
      Type& GetType();
    private:
      Attribute attribute_;
      Geometry geometry_;
      Type type_;
      int Id_;
};

#endif //ITEM_HPP