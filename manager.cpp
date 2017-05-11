#include "manager.h"

Manager::Manager()
{
}

void Manager::addShape(Shape *shape)
{
    myShapes.push_back(shape);
}

void Manager::drawAll(QPainter *painter)
{
    for(int i =0; i < myShapes.size(); ++i  )
    {
        myShapes.at(i)->draw(painter);
    }
}

void Manager::clear()   {

}

bool Manager::isEmpty()  {
    if(myShapes.size() == 0)
    {
        return true;
    }
    return false;
}
