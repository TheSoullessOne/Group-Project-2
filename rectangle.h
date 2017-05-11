#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double x1, double y1, double l, double h);
    QRect getRect() const;

    void draw(QPainter *painter);
    void move();
    double perimeter();
    double area();

private:
    double width;
    double height;
    QPoint point;
    QRect rect;
};

#endif // RECTANGLE_H
