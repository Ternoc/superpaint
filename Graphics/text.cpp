#include "text.h"
#include <QPainter>


void Text::draw(QPainter &painter) const
{
    painter.drawText(x(), y(), width(), height(), Qt::TextWordWrap, text_);
}

void Text::set_text(const QString &user_text)
{
    text_ = user_text;
}

const QString &Text::text() const
{
    return text_;
}
