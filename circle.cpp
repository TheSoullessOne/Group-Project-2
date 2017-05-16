#include "circle.h"

Circle::Circle(double x1, double y1, double r)  {
    point.setX(x1);
    point.setY(y1);
    radius = r;
}

void Circle::draw(QPainter* painter)
{
    painter->setPen(this->getPen());
    painter->setBrush(this->getBrush());
    painter->drawEllipse(point, radius, radius);
}

void Circle::move(){

}

double Circle::perimeter()
{
    return 0;
}

double Circle::area()
{
    return 0;
}
