#ifndef POLYLINE_H
#define POLYLINE_H
#include "Shapes.h"

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::POLYLINE) {}
    Polyline(vector<QPoint> points);

    void draw();
    void move();
    double perimeter();

private:
    vector<QPoint> points;
};

#endif // POLYLINE_H
