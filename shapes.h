#ifndef SHAPE_H
#define SHAPE_H

<<<<<<< HEAD
#include "mainwindow.h"
#include <QPainter>

class Shape : public QPainter
{
public:
    virtual void draw() = 0 {}
    virtual void move() = 0 {}
    virtual void perimeter() = 0 {}

private:
    int shapeId;
    // UNSURE penColor
    // UNSURE penWidth
    // UNSURE penStyle
    // UNSURE penCapStyle
    // UNSURE penJoinStyle
    // UNSURE brushColor
    // UNSURE brushStyle

    // UNSURE = unsure about what type
};

//class Line : public Shape
//{
//public:
//    Line(double x1, double y1, double x2, double y2);

//private:

//};



class PolyLine : public Shape
{
public:
    // Constructor
    PolyLine(){
        arSize = 10;
        points = new QPointF[arSize](0.0, 0.0);
    }

    // Inherited Functions
    virtual void draw(){
        this->drawPolyline(points, arSize);
    }

    virtual void move(){

    }

    virtual void perimeter(){
        return 0;
    }

private:
    QPointF *points;
    int      arSize;
};

=======
#include <QPainter>
//#include "vector.h"
#include <QPoint>
#include <QRect>

class Shape : public QPainter
{
public:
    enum ShapeType {NOSHAPE, LINE, POLYLINE, POLYGON, RECTANGLE, ELLIPSE, CIRCLE, TEXT};

    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = NOSHAPE);
//    virtual ~Shape();
>>>>>>> 4cc6752cbd00fe11930da0c8bb4a521dfadcb5f9

    ShapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

<<<<<<< HEAD
class Polygon : public Shape
{
public:

private:

};

//class Rectangle : public Shape
//{
//public:
//    Rectangle(double x1, double y1, double l, double w);

//private:
//    double length;
//    double width;
//};

class Ellipse : public Shape
{
public:
    Ellipse(double x1, double y1, double Maj, double Min);

private:
    double semiMajor;
    double semiMinor;
};

class Circle : public Shape
{
public:
    Circle(double x1, double y1, double r);

private:
    double radius;
};

class Text : public Shape
{
public:

private:
=======
    void setShape(ShapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setPen(Qt::GlobalColor);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);

    void defaultStyle();
    void drawRect(int width, int height);
    virtual void draw() = 0;
    virtual void move() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;

protected:

    int shapeId;
    ShapeType shape;
//    vector<QPoint> points;
    QPen qPen;
    QBrush qBrush;
>>>>>>> 4cc6752cbd00fe11930da0c8bb4a521dfadcb5f9

};
#endif // SHAPE_H
