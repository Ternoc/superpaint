#include "ellipse.h"
#include <QPainter>


void Ellipse::draw(QPainter &painter) const
{
	painter.drawEllipse(QPoint(x(),y()), rayonx_, rayony_);
}

void Ellipse::set_extents(int a, int b)
{
	rayonx_ =  a - x();
	rayony_ = b - y();
}
