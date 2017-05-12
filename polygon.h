#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "vector.h"

class Polygon : public Shape
{
public:
    Polygon(vector<QPoint> points);

    void draw(QPainter* painter);
    void move();
    double perimeter();
    double area();

private:
    QPolygon myPoly;
};

#endif // POLYGON_H
