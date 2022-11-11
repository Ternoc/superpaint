#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "abstractrectangle.h"

class Rectangle : public AbstractRectangle
{
public:
    void draw(QPainter &painter) const override;
};

#endif // RECTANGLE_H
