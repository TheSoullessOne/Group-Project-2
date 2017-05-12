#ifndef MANAGER_H
#define MANAGER_H

#include "shape.h"
#include "vector.h"
#include <QDebug>

class Manager
{
public:
    Manager();

    vector<Shape*> getVector();
    void addShape(Shape* shape);
    void drawAll(QPainter *painter);
    void clear();
    bool isEmpty();

private:
//    QColor getColor(QString color);
//    Qt::BrushStyle getBrushStyle(QString brushStyle);
    vector<Shape*> myShapes;
};

#endif // MANAGER_H
