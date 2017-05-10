#include "renderarea.h"
#include "rectangle.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
        :   QWidget(parent)
{
//    shape = Polygon;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}



void RenderArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    Rectangle *eRect = new Rectangle(100,100,50,50);

    painter.drawLine(QPoint(10, 10), QPoint(50,50));
    painter.drawRect(eRect->getRect());
}
