#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include "manager.h"
#include <QPainter>
#include <QMessageBox>

class RenderArea : public QWidget
{
public:
    enum class ShapeType { NoShape, Line, PolyLine, Polygon, Rectangle, Ellipse, Circle, Text };

    RenderArea(QWidget *parent = 0);
    Manager* getShapeManager();
    void addThisShape(Shape* shape);
    void draw(int, QPainter *painter);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    Manager* shapeManager;
};

#endif // RENDERAREA_H
