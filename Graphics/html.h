#ifndef HTML_H
#define HTML_H

#include "text.h"

class Html: public Text
{
public:
    void draw(QPainter &painter) const override;
};

#endif // HTML_H
