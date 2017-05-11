#include "Polyline.h"

Polyline::Polyline(vector<QPoint> points)
{
    for(int i = 0; i < points.size(); ++i)  {
        this->points[i] = points[i];
    }
}

//void Polyline::draw()   {

//}

void Polyline::move()   {

}

double Polyline::perimeter()   {
    return 0;
}

double Polyline::area()   {
    return 0;
}
