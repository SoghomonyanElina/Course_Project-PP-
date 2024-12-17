#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

#include <string>

struct Attribute {
    std::string color_;
    std::string line_color_;
    double line_thickness_;
    //Attribute(std::string color, std::string line_color, double line_thickness) 
    //   : color_(color), line_color_(line_color), line_thickness_(line_thickness) {}
};

#endif //ATTRIBUTE_HPP