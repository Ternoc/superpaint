#ifndef ARROWDIRECTED_H
#define ARROWDIRECTED_H
#include "abstractline.h"


class ArrowDirected : public AbstractLine
{
public:
    void draw(QPainter &painter) const override;
};

#endif // ARROWDIRECTED_H
