#ifndef SHAPE_H
#define SHAPE_H

#include "mainwindow.h"
#include "vector.h"
#include <QPoint>
#include <QRect>

class Shape : public QPainter
{
public:
    enum ShapeType {NOSHAPE, LINE, POLYLINE, POLYGON, RECTANGLE, ELLIPSE, CIRCLE, TEXT};

    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NOSHAPE);
//    virtual ~Shape();

    ShapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    void setShape(ShapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setPen(Qt::GlobalColor);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);

    void defaultStyle();
    void drawRect(int width, int height);
    virtual void draw() = 0;
//    virtual void move() = 0 {}
//    virtual double perimeter() = 0 {}

protected:

    int shapeId;
    ShapeType shape;
//    vector<QPoint> points;
    QPen qPen;
    QBrush qBrush;

};

class Line : public Shape
{
public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::LINE) {}
    Line(double x1, double y1, double x2, double y2);

    const void setPoints(const QPoint& temp1, const QPoint& temp2);

    void draw();

private:
    QPoint pointOne;
    QPoint pointTwo;
};


class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::POLYLINE) {}
    Polyline(vector<QPoint> points);

    void draw(const int translate_x = 0, const int translate_y = 0);

private:
    vector<QPoint> points;
};


class Polygon : public Shape
{
public:
    Polygon(vector<QPoint> points);

    void draw(const int translate_x = 0, const int translate_y = 0);

private:
    vector<QPoint> points;
};


class Rectangle : public Shape
{
public:
    Rectangle(double x1, double y1, double l, double w);
    QRect getRect() const;

    void draw();

private:
    double length;
    double width;
    QPoint point;
    QRect rect;
};


class Square : public Shape
{
public:

private:
    double length;
    double width;
    QPoint point;
};

class Ellipse : public Shape
{
public:
    Ellipse(double x1, double y1, double Maj, double Min);

    void draw(const int translate_x = 0, const int translate_y = 0);

private:
    double semiMajor;
    double semiMinor;
    QPoint point;
};


class Circle : public Shape
{
public:
    Circle(double x1, double y1, double r);

    void draw(const int translate_x = 0, const int translate_y = 0);

private:
    double radius;
    QPoint point;
};


class Text : public Shape
{
public:
    void draw(const int translate_x = 0, const int translate_y = 0);

};


class NoShape : public Shape
{
public:
    void draw(const int translate_x = 0, const int translate_y = 0);

};

#endif // SHAPE_H
