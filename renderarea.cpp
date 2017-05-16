//#include "renderarea.h"
#include "rectangle.h"
#include <QDebug>
#include "mainwindow.h"

RenderArea::RenderArea(QWidget *parent):   QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    shapeManager = Manager::getInstance();
}

Manager* RenderArea::getShapeManager(){
    return Manager::getInstance();
}

void RenderArea::addThisShape(Shape* shape)
{
    this->getShapeManager()->addShape(shape);
    update();
}

void RenderArea::draw(int index, QPainter *painter)
{
    this->shapeManager->draw(index, painter);
}

void RenderArea::paintEvent(QPaintEvent * ) {
    // Called when update() is called

    if(!this->getShapeManager()->isEmpty()){
        QPainter *painter = new QPainter(this);
        this->getShapeManager()->drawAll(painter);
        painter->end();
    }
}
