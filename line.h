#ifndef LINE_H
#define LINE_H
#include "Shapes.h"

class Line : public Shape
{
public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::LINE) {}
    Line(double x1, double y1, double x2, double y2);

    const void setPoints(const QPoint& temp1, const QPoint& temp2);

    void draw();
    void move();
    double perimeter();


private:
    QPoint pointOne;
    QPoint pointTwo;
};
#endif // LINE_H
