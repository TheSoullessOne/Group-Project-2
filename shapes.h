#ifndef SHAPE_H
#define SHAPE_H

#include "mainwindow.h"
#include <QPoint>
#include <QRect>

class Shape : public QPainter
{
    int shapeId;
    vector<QPoint> points;
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
    QPoint pointOne;
    QPoint pointTwo;

public:
    Line(double x1, double y1, double x2, double y2);
};


class Polyline : public Shape
{
    Polyline(vector<QPoint> points);

private:
    vector<QPoint> points;
};


class Polygon : public Shape
{
    Polygon(vector<QPoint> points);

private:
    vector<QPoint> points;
};


class Rectangle : public Shape
{
    double length;
    double width;
    QPoint point;
    QRect rect;

public:
    Rectangle(double x1, double y1, double l, double w);
};


class Ellipse : public Shape
{
    double semiMajor;
    double semiMinor;
    QPoint point;

public:
    Ellipse(double x1, double y1, double Maj, double Min);
};


class Circle : public Ellipse
{
    double radius;
    QPoint point;

public:
    Circle(double x1, double y1, double r);

};


class Text : public Shape
{

};

#endif // SHAPE_H
