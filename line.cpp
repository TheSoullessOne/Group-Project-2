#include "Line.h"

Line::Line(double x1, double y1, double x2, double y2)  {
    pointOne.setX(x1);
    pointOne.setY(y1);
    pointTwo.setX(x2);
    pointTwo.setY(y2);
}

void Line::draw(QPainter *painter){
    painter->drawLine(pointOne, pointTwo);
}

void Line::move(){

}

double Line::perimeter(){
    return 0;
}

double Line::area(){
    return 0;
}
