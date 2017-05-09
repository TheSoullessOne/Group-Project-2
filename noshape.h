#ifndef NOSHAPE_H
#define NOSHAPE_H
#include "Shapes.h"

class NoShape : public Shape
{
public:
    void draw();
    void move();
    double perimeter();


};


#endif // NOSHAPE_H
