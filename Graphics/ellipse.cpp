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

bool Ellipse::contains(int x_point, int y_point) const{
   if(rayonx_ == 0 || rayony_ == 0)
      return false;

   auto square = [](auto x){return x*x;};

   return square(x_point - x()) / square(rayonx_) + square(y_point - y()) / square(rayony_) <= 1;
}
