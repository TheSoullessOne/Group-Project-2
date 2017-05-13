#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPoint>
#include <QRect>

class Shape
{
public:
    enum ShapeType {NOSHAPE, LINE, POLYLINE, POLYGON, RECTANGLE, ELLIPSE, CIRCLE, TEXT};

    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = NOSHAPE);
    virtual ~Shape();

    ShapeType getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    void setShape(ShapeType shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setPen(QColor);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);
    void setId(int);
    int getId() const;

    void defaultStyle();
    virtual void draw(QPainter *painter) = 0;
    virtual void move() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;

protected:

    int shapeId;
    ShapeType shape;
    QPen qPen;
    QBrush qBrush;
};
#endif // SHAPE_H
