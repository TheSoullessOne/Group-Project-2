#include "shapes.h"


Line::Line(double x1, double y1, double x2, double y2)  {
    pointOne.setX(x1);
    pointOne.setY(y1);
    pointTwo.setX(x2);
    pointTwo.setY(y2);
}

Polyline::Polyline(vector<QPoint> points)
{
    for(int i = 0; i < points.size(); ++i)  {
        this->points[i] = points[i];
    }
}

Polygon::Polygon(vector<QPoint> points)  {
    for(int i = 0; i < points.size(); ++i)  {
        this->points[i] = points[i];
    }
}


Rectangle::Rectangle(double x1, double y1, double l, double w){
    rect.setTopLeft(QPoint(x1, y1));
    rect.setWidth(w);
    rect.setHeight(l);
}

QRect Rectangle::getRect() const
{
    return rect;
}

Ellipse::Ellipse(double x1, double y1, double Maj, double Min){
    point.setX(x1);
    point.setY(y1);
    semiMajor = Maj;
    semiMinor = Min;
}

Circle::Circle(double x1, double y1, double r)  {
    point.setX(x1);
    point.setY(y1);
    radius = r;
}
