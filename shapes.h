#ifndef SHAPE_H
#define SHAPE_H

#include "mainwindow.h"


class Shape : public QPainter
{
    int shapeId;
    // UNSURE shapeDimensions???
    // UNSURE penColor
    // UNSURE penWidth
    // UNSURE penStyle
    // UNSURE penCapStyle
    // UNSURE penJoinStyle
    // UNSURE brushColor
    // UNSURE brushStyle

    // UNSURE = unsure about what type

public:
    virtual void draw() = 0     {

    }
    virtual void move() = 0     {

    }
    virtual void perimeter() = 0    {

    }
};

class Line : public Shape
{


public:
    Line(double x1, double y1, double x2, double y2);
};
class PolyLine : public Shape
{


private:
    vector<QPoint> points;
};
class Polygon : public Shape
{

};
class Rectangle : public Shape
{
    double length;
    double width;

public:
    Rectangle(double x1, double y1, double l, double w);
};
class Ellipse : public Shape
{
    double semiMajor;
    double semiMinor;

public:
    Ellipse(double x1, double y1, double Maj, double Min);
};
class Circle : public Shape
{
    double radius;

public:
    Circle(double x1, double y1, double r);

};
class Text : public Shape
{

};

#endif // SHAPE_H
