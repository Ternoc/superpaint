#include "line.h"
#include <QPainter>

void Line::draw(QPainter &painter) const
{
    painter.drawLine(x(), y(), x_end(), y_end());
}
