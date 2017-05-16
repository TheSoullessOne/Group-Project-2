#ifndef POLYLINE_H
#define POLYLINE_H
#include "shape.h"
#include "vector.h"

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::POLYLINE) {}
    Polyline(vector<QPoint> points);

    void draw(QPainter *painter);
    void move();
    double perimeter();
    double area();

private:
    QPolygon myPoly;
};

#endif // POLYLINE_H