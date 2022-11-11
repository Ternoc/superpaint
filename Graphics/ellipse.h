#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QPoint>
#include "graphicobject.h"

class Ellipse : public GraphicObject
{
public:
	void draw(QPainter &painter) const override;
	void set_extents(int a, int b) override;
	
protected:
	int rayonx_ =0, rayony_ =0;
	
};

#endif // ELLIPSE_H
