#ifndef MANAGER_H
#define MANAGER_H

#include "shape.h"
#include "vector.h"
#include <QDebug>
#include <QVector>

class Manager
{
public:

    static Manager* getInstance();

    void addShape(Shape* shape);
    void drawAll(QPainter *painter);
    void clear();
    bool isEmpty();
    int size();

private:
    Manager();
//    QColor getColor(QString color);
//    Qt::BrushStyle getBrushStyle(QString brushStyle);
    vector<Shape*> myShapes;
    static Manager* instance;
};

#endif // MANAGER_H
