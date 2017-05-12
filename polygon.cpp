#include "polygon.h"

Polygon::Polygon(vector<QPoint> points)  {
    for(int i = 0; i < points.size(); ++i)  {
        myPoly.insert(i, points[i]);
    }
}

void Polygon::draw(QPainter* painter)
{
    painter->drawPolygon(myPoly);
}

void Polygon::move()
{

}

double Polygon::perimeter()
{
    return 0;
}

double Polygon::area()
{
    return 0;
}
