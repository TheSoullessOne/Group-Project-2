#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <cmath>
class Circle : public Shape
{
public:
    Circle(double x1, double y1, double r);

    void draw(QPainter *painter);
    void move();
    double perimeter();
    double area();

private:
    int radius;
    QPoint point;
};

#endif // CIRCLE_H
