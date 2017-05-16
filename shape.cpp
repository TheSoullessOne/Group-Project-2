#include "shape.h"

Shape::Shape(QPaintDevice *device, int id, Shape::ShapeType shape)
{
    this->shapeId = id;
    this->shape = shape;
}

Shape::~Shape()
{

}

QString Shape::getShape() const
{
    return this->shapeType;
}

const QPen &Shape::getPen() const
{
    return this->qPen;
}

const QBrush &Shape::getBrush() const
{
    return this->qBrush;
}

void Shape::setShape(QString shape)
{
    this->shapeType = shape;
}

void Shape::setPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle capStyle, Qt::PenJoinStyle joinStyle)
{
    this->qPen.setColor(color);
    this->qPen.setWidth(width);
    this->qPen.setStyle(style);
    this->qPen.setCapStyle(capStyle);
    this->qPen.setJoinStyle(joinStyle);
}

void Shape::setPen(QColor color)
{
    this->qPen.setColor(color);
}

void Shape::setBrush(Qt::GlobalColor color, Qt::BrushStyle style)
{
    this->qBrush.setColor(color);
    this->qBrush.setStyle(style);
}

void Shape::setId(int id)
{
    this->shapeId = id;
}

int Shape::getId() const
{
    return this->shapeId;
}

void Shape::setDimensions(QStringList parsedPoints)
{
    for(int i = 0; i < parsedPoints.size(); ++i)
    {
        dimensions.push_back(parsedPoints[i].toInt());
    }
}

void Shape::printDimensions(QTextStream& output)
{
    for(int i = 0; i < dimensions.size(); ++i)
    {
        output << QString::number(dimensions[i]);
        if(i != (dimensions.size() - 1))
            output << ", ";
    }
}

void Shape::printPen(QTextStream &output)
{
    output << "PenColor: ";
    output << this->convertColorToString(this->qPen.color());
    output << endl;
    output << "PenWidth: ";
    output << this->qPen.width();
    output << endl;
    output << "PenStyle: ";
    output << this->convertPenStyleToString(this->qPen.style());
    output << endl;
    output << "PenCapStyle: ";
    output << this->convertPenCapStyleToString(this->qPen.capStyle());
    output << endl;
    output << "PenJoinStyle: ";
    output << this->convertPenJoinStyleToString(this->qPen.joinStyle());
    output << endl;
}

void Shape::printBrush(QTextStream &output)
{
    output << "BrushColor: ";
    output << this->convertColorToString(this->qBrush.color());
    output << endl;
    output << "BrushStyle: ";
    output << this->convertBrushStyleToString(this->qBrush.style());
    output << endl;
}

QString Shape::convertColorToString(QColor penColor)
{
    QString color;
    if(penColor == Qt::white)
    {
        color = "white";
    }
    else if(penColor == Qt::black)
    {
        color = "black";
    }
    else if(penColor == Qt::red)
    {
        color = "red";
    }
    else if(penColor == Qt::green)
    {
        color = "green";
    }
    else if(penColor == Qt::blue)
    {
        color = "blue";
    }
    else if(penColor == Qt::cyan)
    {
        color = "cyan";
    }
    else if(penColor == Qt::magenta)
    {
        color = "magenta";
    }
    else if(penColor == Qt::yellow)
    {
        color = "yellow";
    }
    else if(penColor == Qt::gray)
    {
        color == "gray";
    }
    return color;
}

QString Shape::convertPenStyleToString(Qt::PenStyle disPenStyle)
{
    QString penStyle;
    if(disPenStyle == Qt::PenStyle::NoPen)
    {
        penStyle = "NoPen";
    }
    else if(disPenStyle == Qt::PenStyle::SolidLine)
    {
        penStyle = "SolidLine";
    }
    else if(disPenStyle == Qt::PenStyle::DashLine)
    {
        penStyle = "DashLine";
    }
    else if(disPenStyle == Qt::PenStyle::DotLine)
    {
        penStyle = "DotLine";
    }
    else if(disPenStyle == Qt::PenStyle::DashDotLine)
    {
        penStyle = "DashDotLine";
    }
    else if(disPenStyle == Qt::PenStyle::DashDotDotLine)
    {
        penStyle = "DashDotDotLine";
    }
    return penStyle;
}

QString Shape::convertPenCapStyleToString(Qt::PenCapStyle style)
{
    QString cap;
    if(style == Qt::PenCapStyle::FlatCap)
    {
        cap = "FlatCap";
    }
    else if(style == Qt::PenCapStyle::SquareCap)
    {
        cap = "SquareCap";
    }
    else if(style == Qt::PenCapStyle::RoundCap)
    {
        cap = "RoundCap";
    }
    return cap;
}

QString Shape::convertPenJoinStyleToString(Qt::PenJoinStyle style)
{
    QString join;
    if(style == Qt::PenJoinStyle::MiterJoin)
    {
        join = "MiterJoin";
    }
    else if(style == Qt::PenJoinStyle::BevelJoin)
    {
        join = "BevelJoin";
    }
    else if(style == Qt::PenJoinStyle::RoundJoin)
    {
        join = "RoundJoin";
    }
    return join;
}

QString Shape::convertBrushStyleToString(Qt::BrushStyle style)
{
    QString brush;
    if(style == Qt::BrushStyle::SolidPattern)
    {
        brush = "SolidPattern";
    }
    else if(style == Qt::BrushStyle::HorPattern)
    {
        brush = "HorPattern";
    }
    else if(style == Qt::BrushStyle::VerPattern)
    {
        brush = "VerPattern";
    }
    else if(style == Qt::BrushStyle::NoBrush)
    {
        brush = "NoBrush";
    }
    return brush;
}

