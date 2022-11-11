#ifndef ABSTRACTLINE_H
#define ABSTRACTLINE_H
#include "graphicobject.h"


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

protected:
    int x_end() const {return x_end_;}
    int y_end() const {return y_end_;}

private:
    int x_end_ = 0, y_end_ = 0;
};
#endif // ABSTRACTLINE_H
