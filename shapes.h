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
    virtual void move() = 0;
    virtual double perimeter() = 0;

protected:

    int shapeId;
    ShapeType shape;
//    vector<QPoint> points;
    QPen qPen;
    QBrush qBrush;

};
#endif // SHAPE_H
