#ifndef POLYGON_H
#define POLYGON_H
#include "Shapes.h"
#include "vector.h"

class Polygon : public Shape
{
public:
    Polygon(vector<QPoint> points);

    void draw();
    void move();
    double perimeter();
    double area();

private:
    vector<QPoint> points;
};

#endif // POLYGON_H
