#include "renderarea.h"
#include "rectangle.h"

#include <QDebug>

RenderArea::RenderArea(QWidget *parent):   QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    shapeManager = Manager::getInstance();
    this->addThisShape(new Rectangle(10,10,50,50));
}

Manager* RenderArea::getShapeManager(){
    return Manager::getInstance();
}

void RenderArea::addThisShape(Shape* shape)
{
    qDebug() << "Inside add this shape";
    this->getShapeManager()->addShape(shape);
    qDebug() << "About to update";
    update();
    qDebug() << "finished updating";
}

void RenderArea::paintEvent(QPaintEvent * ) {
    qDebug() << "MYSHAPES SIZE:";
    qDebug() << this->getShapeManager()->size();
    // Called when update() is called
    if(!this->getShapeManager()->isEmpty()){
        QPainter *painter = new QPainter(this);
        this->getShapeManager()->drawAll(painter);
        painter->end();
    }
    else
    {
        qDebug() << "manager is empty";
    }
}
