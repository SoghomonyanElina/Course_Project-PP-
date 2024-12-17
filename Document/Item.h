#ifndef ITEM_HPP
#define ITEM_HPP

#include "Attribute.h"
#include "Geometry.h"
#include "Type.h"
#include <memory>

class Item {
    public:
      Item() = default;
      void SetGeometry(const Geometry& geometry);
      Geometry& GetGeometry();
      void SetAttribute(const Attribute& attribute);
      Attribute& GetAttribute();
      void SetType(const Type& type);
      Type& GetType();
    private:
      Attribute attribute_;
      Geometry geometry_;
      Type type_;
      int Id_;
};

#endif //ITEM_HPP