#ifndef MANAGER_H
#define MANAGER_H

#include "shapes.h"
#include "vector.h"

class manager
{
public:
    manager();


    void addShape(Shape *shape);
    void drawAll(QPainter *painter);
    void clear();
    bool isEmpty();

private:
//    QColor getColor(QString color);
//    Qt::BrushStyle getBrushStyle(QString brushStyle);
    QVector<Shape*> myShapes;
};

#endif // MANAGER_H
