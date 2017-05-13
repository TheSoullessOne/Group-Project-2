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
    for( int i = 0; i < arSize; i++ )
    {
        // Old Points = Newly Specified Points
        // Using void QPointF::setX(qreal x)
        // Where qreal is typedef for double
        // How are we getting the users' input???
    }

    // Re-draw
    this->draw();
}

double Polyline::perimeter()   {
    return 0;
}

double Polyline::area()   {
    return 0;
}
