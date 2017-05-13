#include "square.h"

Square::Square(int x1, int y1, int length)
{
    point.setX(x1);
    point.setY(y1);
    this->length = length;
    rect.setTopLeft(point);
    rect.setWidth(length);
    rect.setHeight(length);
}

void Square::draw(QPainter *painter)
{
    painter->drawRect(rect);
}

void Square::move()
{

}

double Square::perimeter()
{
    return length * length;
}

double Square::area()
{
    return this->length * 4;
}
