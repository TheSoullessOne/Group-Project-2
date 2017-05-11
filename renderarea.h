#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include "manager.h"

class RenderArea : public QWidget
{
public:
    RenderArea(QWidget *parent = 0);
    manager* getShapeManager();
    void addThisShape(Shape* shape);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    manager* shapeManager;
};

#endif // RENDERAREA_H
