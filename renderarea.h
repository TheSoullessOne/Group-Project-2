#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include "manager.h"

class RenderArea : public QWidget
{
public:
    enum class ShapeType { NoShape, Line, PolyLine, Polygon, Rectangle, Ellipse, Circle, Text };

    RenderArea(QWidget *parent = 0);
    manager* getShapeManager();
    void addThisShape(Shape* shape);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    ShapeType shape;
    QPen      pen;
    QBrush    brush;
    bool      antialiased;
    bool      transformed;
    manager* shapeManager;
};

#endif // RENDERAREA_H
