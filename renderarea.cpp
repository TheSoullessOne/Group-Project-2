#include "renderarea.h"
#include "rectangle.h"

#include <QDebug>

RenderArea::RenderArea(QWidget *parent):   QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    this->shapeManager = new Manager();
    this->getShapeManager()->addShape(new Rectangle(10,10,50,50));

}

Manager* RenderArea::getShapeManager(){
    return this->shapeManager;
}

void RenderArea::addThisShape(Shape* shape){
    this->shapeManager->addShape(shape);
//    update();
}

void RenderArea::paintEvent(QPaintEvent *event) {
    // Called when update() is called
    if(!this->shapeManager->isEmpty()){
        qDebug() << "Inside if statement";
        QPainter *painter = new QPainter(this);
        qDebug() << "Created painter device";
        this->shapeManager->drawAll(painter);
        qDebug() << "Called drawall";
        painter->end();
    }
    else
    {
        qDebug() << "manager is empty";
    }
}
