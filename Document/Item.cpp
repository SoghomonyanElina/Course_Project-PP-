#include "Item.h"

void Item::SetGeometry(Geometry& geometry) {
    geometry_ = geometry;
}

Geometry& Item::GetGeometry() {
    return geometry_;
}

void Item::SetAttribute(Attribute& attribute) {
    attribute_ = attribute;
}

Attribute& Item::GetAttribute() {
    return attribute_;
}

void Item::SetType(Type& type) {
    type_ = type;
}

Type& Item::GetType() {
    return type_;
}