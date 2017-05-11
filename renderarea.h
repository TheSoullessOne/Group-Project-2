#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include "manager.h"
#include <QPainter>

class RenderArea : public QWidget
{
public:
    enum class ShapeType { NoShape, Line, PolyLine, Polygon, Rectangle, Ellipse, Circle, Text };

    RenderArea(QWidget *parent = 0);
    Manager* getShapeManager();
    void addThisShape(Shape* shape);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
<<<<<<< HEAD
    ShapeType shape;
    QPen      pen;
    QBrush    brush;
    bool      antialiased;
    bool      transformed;
    manager* shapeManager;
=======
    Manager* shapeManager;
>>>>>>> 751f56418ceeb9d1ff967b1a752c72659bc9ba6d
};

#endif // RENDERAREA_H
