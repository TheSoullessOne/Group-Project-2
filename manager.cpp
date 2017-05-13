#include "manager.h"

Manager* Manager::instance = 0;

Manager::Manager()
{
    this->myShapes.clear();
}

Manager *Manager::getInstance()
{
    if(instance == NULL)
    {
        instance = new Manager();
    }
    return instance;
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
    return myShapes.size() == 0;
}

int Manager::size()
{
    return myShapes.size();
}
