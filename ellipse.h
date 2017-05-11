#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shapes.h"

class Ellipse : public Shape
{
public:
    Ellipse(double x1, double y1, double Maj, double Min);

    void draw();
    void move();
    double perimeter();
    double area();

private:
    double semiMajor;
    double semiMinor;
    QPoint point;
};


#endif // ELLIPSE_H
