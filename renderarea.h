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
    RenderArea(QWidget *parent = 0);
    Manager* getShapeManager();
    void addThisShape(Shape* shape);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    Manager* shapeManager;
};

#endif // RENDERAREA_H
