#ifndef RECTANGLEAREA_H
#define RECTANGLEAREA_H
#include "graphicobject.h"


class AbstractRectangle : public GraphicObject
{
public:
    virtual void set_extents(int a, int b) override
    {
        width_ = a - x();
        height_ = b - y();
    }

protected:
    int width() const {return width_;}
    int height() const {return height_;}

private:
    int width_ = 0, height_ = 0;
};

#endif // RECTANGLEAREA_H
