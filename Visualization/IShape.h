#ifndef ISHAPE_HPP
#define ISHAPE_HPP

class IShape {
    public:
      virtual void print() = 0;
      virtual void draw() = 0;
};

#endif //ISHAPE_HPP