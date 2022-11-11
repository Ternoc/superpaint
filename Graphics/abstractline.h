#ifndef ABSTRACTLINE_H
#define ABSTRACTLINE_H

#include "graphicobject.h"
#include <algorithm>


class AbstractLine : public GraphicObject
{
public:
   virtual void set_extents(int a, int b) override
   {
      x_end_ = a;
      y_end_ = b;
   }

   virtual void set_initial_position(int x, int y) override {
      GraphicObject::set_initial_position(x,y);
      x_end_ = x;
      y_end_ = y;
   }

   void shift_position(int dx, int dy) override{
      GraphicObject::shift_position(dx, dy);
      x_end_ += dx;
      y_end_ += dy;
   }

   bool contains(int x_point, int y_point) const override {
      const auto xa = x_point - x();
      const auto ya = y_point - y();
      const auto xb = x_end() - x_point;
      const auto yb = y_end() - y_point;

      const auto margin = 10;
      const auto line_length = std::sqrt(std::pow(x_end() - x(), 2) + std::pow(y_end() - y(), 2));

      const auto delta = xa * yb - xb * ya;

      return std::abs(delta) <= margin * line_length &&
            x_point <= std::max(x(), x_end()) &&
            x_point >= std::min(x(), x_end()) &&
            y_point <= std::max(y(), y_end()) &&
            y_point >= std::min(y(), y_end())
            ;
   }

protected:
   int x_end() const {return x_end_;}
   int y_end() const {return y_end_;}

private:
   int x_end_ = 0, y_end_ = 0;
};
#endif // ABSTRACTLINE_H
