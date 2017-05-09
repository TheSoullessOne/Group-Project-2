#ifndef TEXT_H
#define TEXT_H
#include "Shapes.h"

class Text : public Shape
{
public:
    void draw(const int translate_x = 0, const int translate_y = 0);

};


#endif // TEXT_H
