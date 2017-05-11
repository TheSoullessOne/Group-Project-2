#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
public:
    Circle(double x1, double y1, double r);

//    void draw();
    void move();
    double perimeter();
    double area();

private:
    double radius;
    QPoint point;
};

#endif // CIRCLE_H
