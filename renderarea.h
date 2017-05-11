#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include "manager.h"

class RenderArea : public QWidget
{
public:
<<<<<<< HEAD
    enum class ShapeType { NoShape, Line, PolyLine, Polygon, Rectangle, Ellipse, Circle, Text };

=======
>>>>>>> 4cc6752cbd00fe11930da0c8bb4a521dfadcb5f9
    RenderArea(QWidget *parent = 0);
    manager* getShapeManager();
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
=======
    manager* shapeManager;
>>>>>>> 4cc6752cbd00fe11930da0c8bb4a521dfadcb5f9
};

#endif // RENDERAREA_H
