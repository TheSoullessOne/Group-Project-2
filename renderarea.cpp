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

manager* RenderArea::getShapeManager(){
    return this->shapeManager;
}

void RenderArea::addThisShape(Shape* shape){
    this->shapeManager->addShape(shape);
    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */) {
        // Called when update() is called
        if(!this->shapeManager->isEmpty()){
            QPainter *painter = new QPainter(this);
        this->shapeManager->drawAll(painter);
        painter->end();
    }
}
