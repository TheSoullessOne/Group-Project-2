#ifndef TEXT_H
#define TEXT_H
#include "Shapes.h"

class Text : public Shape
{
public:
    void draw();
    void move();
    double perimeter();
    double area();

};


#endif // TEXT_H
