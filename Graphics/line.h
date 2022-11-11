#ifndef LINE_H
#define LINE_H
#include "abstractline.h"


class Line : public AbstractLine
{
public:
    void draw(QPainter &painter) const override;
};

#endif // LINE_H
