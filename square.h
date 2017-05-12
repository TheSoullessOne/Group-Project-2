#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
public:
    Square(int x1, int y1, int length);

    void draw(QPainter *painter);
    void move();
    double perimeter();
    double area();

private:
    double length;
    QPoint point;
    QRect rect;
};

#endif // SQUARE_H
