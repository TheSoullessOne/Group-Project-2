#ifndef MANAGER_H
#define MANAGER_H

#include "shape.h"
#include "vector.h"
#include <QDebug>
#include <QVector>

class Manager
{
public:
    Manager();

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
