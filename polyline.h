#ifndef POLYLINE_H
#define POLYLINE_H
#include "shape.h"
#include "vector.h"

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::POLYLINE) {}
    Polyline();

<<<<<<< HEAD
    void draw();
=======
    void draw(QPainter *painter);
>>>>>>> 364ad6cb29646d716e66cc8e3579d101441069d3
    void move();
    double perimeter();
    double area();

private:
<<<<<<< HEAD
    QPointF *points;
    int      arSize;
=======
    QPolygon myPoly;
>>>>>>> 364ad6cb29646d716e66cc8e3579d101441069d3
};

#endif // POLYLINE_H
