#include "manager.h"

manager::manager()
{
}

void manager::addShape(Shape *shape){
    myShapes.push_back(shape);
}

void manager::drawAll(QPainter *painter){
    for(int i =0; i < myShapes.size(); ++i  ){
        myShapes.at(i)->draw();
    }
}

void manager::clear()   {

}

bool manager::isEmpty()  {
    if(myShapes.size() == 0)
    {
        return true;
    }
    return false;
}
