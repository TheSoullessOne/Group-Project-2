#include "rectangle.h"

Rectangle::Rectangle(double x1, double y1, double l, double w){
    rect.setTopLeft(QPoint(x1, y1));
    rect.setWidth(w);
    rect.setHeight(l);
}

QRect Rectangle::getRect() const
{
    return rect;
}

void Rectangle::draw()
{

}
