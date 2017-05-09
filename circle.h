#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shapes.h"

class Circle : public Shape
{
public:
    Circle(double x1, double y1, double r);

    void draw(const int translate_x = 0, const int translate_y = 0);

private:
    double radius;
    QPoint point;
};

#endif // CIRCLE_H
