#include "Polyline.h"

Polyline::Polyline(vector<QPoint> points)
{
    for(int i = 0; i < points.size(); ++i)  {
        myPoly.insert(i, points[i]);
    }
}

void Polyline::draw(QPainter *painter)
{
    painter->drawPolyline(myPoly);
}

void Polyline::move()   {

}

double Polyline::perimeter()   {
    return 0;
}

double Polyline::area()   {
    return 0;
}
