#include "Ellipse.h"

Ellipse::Ellipse(double x1, double y1, double Maj, double Min){
    point.setX(x1);
    point.setY(y1);
    semiMajor = Maj;
    semiMinor = Min;
}
