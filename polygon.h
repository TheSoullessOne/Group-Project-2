#ifndef POLYGON_H
#define POLYGON_H
#include "Shapes.h"

class Polygon : public Shape
{
public:
    Polygon(vector<QPoint> points);

    void draw();
    void move();
    double perimeter();


private:
    vector<QPoint> points;
};

#endif // POLYGON_H
