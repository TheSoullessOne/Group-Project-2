#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse(double x1, double y1, double Maj, double Min);

    void draw(QPainter* painter);
    void move();
    double perimeter();
    double area();

private:
    int semiMajor;
    int semiMinor;
    QPoint point;
};


#endif // ELLIPSE_H
