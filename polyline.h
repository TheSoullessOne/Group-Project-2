#ifndef POLYLINE_H
#define POLYLINE_H
#include "Shapes.h"
#include "vector.h"

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::POLYLINE) {}
    Polyline();

    void draw();
    void move();
    double perimeter();
    double area();

private:
    QPointF *points;
    int      arSize;
};

#endif // POLYLINE_H
