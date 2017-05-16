#ifndef TEXT_H
#define TEXT_H
#include "shape.h"
#include <QColor>


class Text : public Shape
{
public:
    Text(int,int,int,int);

    void setText(QString);
    QString getText() const;

    void setTextColor(QColor);
    QColor getTextColor() const;

    void setAlignFlag(Qt::AlignmentFlag);
    Qt::AlignmentFlag getAlignFlag() const;

    void setTextPointSize(int);
    int getTextPointSize() const;

    void setFontStyle(QFont::Style);
    QFont::Style getFontStyle() const;

    void setFontWeight(QFont::Weight);
    int getFontWeight() const;

    void setFontFamily(QString);
    QString getFontFamily() const;

    static void printTextStuff(QTextStream &output, Text *textShape);
    QString convertAlignmentToString(Qt::AlignmentFlag);

    void draw(QPainter* painter);
    void move();
    double perimeter();
    double area();

private:
    QRect rect;
    QString text;
    QFont font;
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag flag;
};


#endif // TEXT_H
