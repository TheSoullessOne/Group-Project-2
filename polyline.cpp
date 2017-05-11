#include "Polyline.h"

Polyline::Polyline()
{
    arSize = 10;

    points = new QPointF[arSize];
}

<<<<<<< HEAD
void Polyline::draw()   {
    this->drawPolyline(points, arSize);
}
=======
//void Polyline::draw()   {

//}
>>>>>>> 751f56418ceeb9d1ff967b1a752c72659bc9ba6d

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
