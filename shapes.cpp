#include "shapes.h"

Shape::Shape(QPaintDevice *device, int id, Shape::ShapeType shape)  : QPainter(device)
{
    this->shapeId = id;
    this->shape = shape;
}

Shape::ShapeType Shape::getShape() const
{
    return this->shape;
}

const QPen &Shape::getPen() const
{
    return this->qPen;
}

const QBrush &Shape::getBrush() const
{
    return this->qBrush;
}

void Shape::setShape(Shape::ShapeType shape)
{
    this->shape = shape;
}

void Shape::setPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle capStyle, Qt::PenJoinStyle joinStyle)
{
    this->qPen.setColor(color);
    this->qPen.setWidth(width);
    this->qPen.setStyle(style);
    this->qPen.setCapStyle(capStyle);
    this->qPen.setJoinStyle(joinStyle);
}

void Shape::setPen(Qt::GlobalColor color)
{
    this->qPen.setColor(color);
}

void Shape::setBrush(Qt::GlobalColor color, Qt::BrushStyle style)
{
    this->qBrush.setColor(color);
    this->qBrush.setStyle(style);
}