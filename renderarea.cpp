#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
        :   QWidget(parent)
{
    shape = Polygon;
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}

void RenderArea::setShape(ShapeType shape)  {
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen){
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::paintEvent(QPaintEvent *event) {
    static const QPoint points[4] =
    {
        QPoint(10,80),
        QPoint(20,10),
        QPoint(80,30),
        QPoint(90,70)
    };


}
