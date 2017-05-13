#include "Polyline.h"

<<<<<<< HEAD
Polyline::Polyline()    {
    arSize = 10;
    points = new QPointF[arSize];
}

void Polyline::draw()   {
    QPainter painter(this);
    painter.drawPolyline(points, arSize);
=======
Polyline::Polyline(vector<QPoint> points)
{
    for(int i = 0; i < points.size(); ++i)  {
        myPoly.insert(i, points[i]);
    }
}

void Polyline::draw(QPainter *painter)
{
    painter->drawPolyline(myPoly);
>>>>>>> 364ad6cb29646d716e66cc8e3579d101441069d3
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
