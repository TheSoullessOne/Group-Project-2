#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>

class RenderArea : public QWidget
{
public:
    enum ShapeType {NOSHAPE, LINE, POLYLINE, POLYGON, RECTANGLE, ELLIPSE, CIRCLE, TEXT};

    RenderArea(QWidget *parent = 0);

public slots:
    void setShape(ShapeType shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    ShapeType shape;
    QPen pen;
    QBrush brush;
};

#endif // RENDERAREA_H
