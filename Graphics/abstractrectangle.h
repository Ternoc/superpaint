#ifndef RECTANGLEAREA_H
#define RECTANGLEAREA_H
#include "graphicobject.h"

#include <algorithm>

class AbstractRectangle : public GraphicObject
{
public:
   virtual void set_extents(int a, int b) override
   {
      width_ = a - x();
      height_ = b - y();
   }

   bool contains(int x_point, int y_point) const override{
      const auto x_end = x() + width();
      const auto y_end = y() + height();

      return x_point <= std::max(x(), x_end) &&
            x_point >= std::min(x(), x_end) &&
            y_point <= std::max(y(), y_end) &&
            y_point >= std::min(y(), y_end)
            ;
   }

protected:
   int width() const {return width_;}
   int height() const {return height_;}

private:
   int width_ = 0, height_ = 0;
};

#endif // RECTANGLEAREA_H
