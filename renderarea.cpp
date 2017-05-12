#include "renderarea.h"
#include "rectangle.h"

#include <QDebug>

RenderArea::RenderArea(QWidget *parent):   QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    this->shapeManager = new Manager();
//    this->getShapeManager()->addShape(new Rectangle(10,10,50,50));

}

Manager* RenderArea::getShapeManager(){
    return this->shapeManager;
}

void RenderArea::addThisShape(Shape* shape)
{
    qDebug() << "Inside add this shape";
    this->shapeManager->addShape(shape);
    qDebug() << "About to update";
    update();
    qDebug() << "finished updating";
}

void RenderArea::paintEvent(QPaintEvent *event) {
    // Called when update() is called
    if(!this->shapeManager->isEmpty()){
        QPainter *painter = new QPainter(this);
        this->shapeManager->drawAll(painter);
        painter->end();
    }
    else
    {
        qDebug() << "manager is empty";
    }
}
