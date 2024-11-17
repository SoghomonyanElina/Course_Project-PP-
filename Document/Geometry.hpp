#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

struct Geometry {
    double x_ = 0.0; //Coordinates of the center
    double y_ = 0.0; //Coordinates of the center
    double dist_1_ = 2.0; //Distance from center
    double dist_2_ = 2.0; //Distance from center
    Geometry(double x = 0.0, double y = 0.0, double dist_1 = 2.0, double dist_2 = 2.0)
        : x_(x), y_(y), dist_1_(dist_1), dist_2_(dist_2) {}
};

#endif //GEOMETRY_HPP