#include "polygon.h"

Polygon::Polygon(vector<QPoint> points)  {
    for(int i = 0; i < points.size(); ++i)  {
        this->points[i] = points[i];
    }
}

void Polygon::draw()    {

}

void Polygon::move()    {

}

double Polygon::perimeter()    {

}
