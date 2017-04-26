#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>

class RenderArea : public QWidget
{
public:
    enum class ShapeType {NoShape, Line, PolyLine, Polygon, Rectangle, Ellipse, Cricle, Text };

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void setShape(ShapeType shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    ShapeType shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
};

#endif // RENDERAREA_H
