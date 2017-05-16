#include "text.h"

Text::Text(int x, int y, int l, int h)
{
    rect.setTopLeft(QPoint(x, y));
    rect.setWidth(l);
    rect.setHeight(h);
}

void Text::setText(QString text)
{
    this->text = text;
}

QString Text::getText() const
{
    return text;
}

void Text::setTextColor(QColor color)
{
    this->setPen(color);
}

QColor Text::getTextColor() const
{
    return this->getPen().color();
}

void Text::setAlignFlag(Qt::AlignmentFlag align)
{
    this->flag = align;
}

Qt::AlignmentFlag Text::getAlignFlag() const
{
    return flag;
}

void Text::setTextPointSize(int temp)
{
    this->font.setPointSize(temp);
}

int Text::getTextPointSize() const
{
    return this->font.pointSize();
}

void Text::setFontStyle(QFont::Style style)
{
    this->font.setStyle(style);
}

QFont::Style Text::getFontStyle() const
{
    return this->font.style();
}

void Text::setFontWeight(QFont::Weight weight)
{
    this->font.setWeight(weight);
}

int Text::getFontWeight() const
{
    return this->font.weight();
}

void Text::setFontFamily(QString family)
{
    this->font.setFamily(family);
}

QString Text::getFontFamily() const
{
    return font.family();
}

void Text::printTextStuff(QTextStream &output, Text *textShape)
{
    output << "TextString: ";
    output << textShape->text;
    output << endl;
    output << "TextColor: ";
    output << textShape->convertColorToString(textShape->qPen.color());
    output << endl;
    output << "TextAlignment: ";
    output << textShape->convertAlignmentToString(textShape->flag);
    output << endl;
    output << "TextPointSize: ";
    output << textShape->font.pointSize();
    output << endl;
    output << "TextFontFamily: ";
    output << textShape->font.family();
    output << endl;
    output << "TextFontStyle: ";
    output << textShape->font.style();
    output << endl;
    output << "TextFontWeight: ";
    output << textShape->font.weight();
    output << endl;
}

QString Text::convertAlignmentToString(Qt::AlignmentFlag flag)
{
    QString text;
    if(flag == Qt::AlignmentFlag::AlignLeft)
    {
        text = "AlignLeft";
    }
    else if(flag == Qt::AlignmentFlag::AlignRight)
    {
        text = "AlignRight";
    }
    else if(flag == Qt::AlignmentFlag::AlignTop)
    {
        text = "AlignTop";
    }
    else if(flag == Qt::AlignmentFlag::AlignBottom)
    {
        text = "AlignBottom";
    }
    else if(flag == Qt::AlignmentFlag::AlignCenter)
    {
        text = "AlignCenter";
    }
    return text;
}

void Text::draw(QPainter* painter)
{
    painter->setPen(this->getPen());
    painter->setFont(font);
    painter->drawText(rect, flag, text);
}

void Text::move()
{

}

double Text::perimeter()
{
    return rect.width() * 2 + rect.height() * 2;
}

double Text::area()
{
    return rect.width() * rect.height();
}
