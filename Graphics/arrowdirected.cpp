#include "arrowdirected.h"
#include <QPainter>
#include <cmath>

void ArrowDirected::draw(QPainter &painter) const
{
    painter.drawLine(x(), y(), x_end(), y_end());
    painter.drawEllipse(x_end()-5,y_end()-5,10,10);
}
