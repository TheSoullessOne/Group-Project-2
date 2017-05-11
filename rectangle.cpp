#include "rectangle.h"

Rectangle::Rectangle(double x1, double y1, double w, double h){
    width = w;
    height = h;
    point.setX(x1);
    point.setY(y1);
    rect.setTopLeft(point);
    rect.setWidth(width);
    rect.setHeight(height);
}

QRect Rectangle::getRect() const
{
    return rect;
}

void Rectangle::draw(QPainter *painter)
{
    painter->drawRect(this->getRect());
}

void Rectangle::move()
{

}

double Rectangle::perimeter()
{

    return 0;
}

double Rectangle::area()
{

    return 0;
}
