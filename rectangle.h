#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shapes.h"

class Rectangle : public Shape
{
public:
    Rectangle(double x1, double y1, double l, double w);
    QRect getRect() const;

    void draw();

private:
    double length;
    double width;
    QPoint point;
    QRect rect;
};

#endif // RECTANGLE_H
