#include "rectangle.h"
#include <QPainter>


void Rectangle::draw(QPainter &painter) const
{
    painter.drawRect(x(),y(),width(),height());
}

