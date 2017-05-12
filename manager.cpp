#include "manager.h"

Manager::Manager()
{
}

vector<Shape*> Manager::getVector()
{
    return this->myShapes;
}

void Manager::addShape(Shape *shape)
{
    qDebug() << "Inside add shape";
    this->myShapes.push_back(shape);
}

void Manager::drawAll(QPainter *painter)
{
    for(int i =0; i < myShapes.size(); ++i  )
    {
        myShapes[i]->draw(painter);
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
