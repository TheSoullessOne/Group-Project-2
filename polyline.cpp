#include "Polyline.h"

Polyline::Polyline(vector<QPoint> points)
{
    for(int i = 0; i < points.size(); ++i)  {
        this->points[i] = points[i];
    }
}

