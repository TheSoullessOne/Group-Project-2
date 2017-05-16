#include "Ellipse.h"

Ellipse::Ellipse(double x1, double y1, double Maj, double Min){
    point.setX(x1);
    point.setY(y1);
    semiMajor = Maj;
    semiMinor = Min;
}

void Ellipse::draw(QPainter* painter)
{
    painter->setPen(this->getPen());
    painter->setBrush(this->getBrush());
    painter->drawEllipse(point, semiMajor, semiMinor);
}

void Ellipse::move(){

}

double Ellipse::perimeter()
{
    return 0;
}

double Ellipse::area()
{
    return 0;
}
