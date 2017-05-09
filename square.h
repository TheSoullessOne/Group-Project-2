#ifndef SQUARE_H
#define SQUARE_H
#include "Shapes.h"

class Square : public Shape
{
public:
    void draw();
    void move();
    double perimeter();


private:
    double length;
    double width;
    QPoint point;
};

#endif // SQUARE_H
