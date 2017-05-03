#include "renderarea.h"
#include "shapes.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
        :   QWidget(parent)
{
//    shape = Polygon;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
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
    QPainter painter(this);
    Rectangle eRect(100,100,50,50);

    painter.drawLine(QPoint(10, 10), QPoint(50,50));
    painter.drawRect(eRect.getRect());
}
