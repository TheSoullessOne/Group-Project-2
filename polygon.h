#ifndef POLYGON_H
#define POLYGON_H
#include "Shapes.h"

class Polygon : public Shape
{
public:
    Polygon(vector<QPoint> points);

    void draw(const int translate_x = 0, const int translate_y = 0);

private:
    vector<QPoint> points;
};

#endif // POLYGON_H
