#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
public:
//    void draw(QPainter *painter);
    void move();
    double perimeter();
    double area();

private:
    double length;
    double width;
    QPoint point;
};

#endif // SQUARE_H
