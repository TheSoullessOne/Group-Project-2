#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPoint>
#include <QRect>
#include "vector.h"

class Shape
{
public:
    enum ShapeType {NOSHAPE, LINE, POLYLINE, POLYGON, RECTANGLE, ELLIPSE, CIRCLE, TEXT};

    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = NOSHAPE);
    virtual ~Shape();

    QString getShape() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    void setShape(QString shape);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void setPen(QColor);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);
    void setId(int);
    int getId() const;
    void setDimensions(QStringList);
    void printDimensions(QTextStream &output);
    void printPen(QTextStream &output);
    void printBrush(QTextStream &output);
    QString convertColorToString(QColor);
    QString convertPenStyleToString(Qt::PenStyle);
    QString convertPenCapStyleToString(Qt::PenCapStyle);
    QString convertPenJoinStyleToString(Qt::PenJoinStyle);
    QString convertBrushStyleToString(Qt::BrushStyle);

    void defaultStyle();
    virtual void draw(QPainter *painter) = 0;
    virtual void move() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;

protected:
    vector<int> dimensions;
    QString shapeType;
    int shapeId;
    ShapeType shape;
    QPen qPen;
    QBrush qBrush;

};
#endif // SHAPE_H
