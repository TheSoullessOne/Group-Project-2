#ifndef NOSHAPE_H
#define NOSHAPE_H
#include "Shapes.h"

class NoShape : public Shape
{
public:
    void draw(const int translate_x = 0, const int translate_y = 0);

};


#endif // NOSHAPE_H
