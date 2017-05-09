#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shapes.h"

class Ellipse : public Shape
{
public:
    Ellipse(double x1, double y1, double Maj, double Min);

    void draw(const int translate_x = 0, const int translate_y = 0);

private:
    double semiMajor;
    double semiMinor;
    QPoint point;
};


#endif // ELLIPSE_H
