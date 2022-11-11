#include "html.h"
#include <QPainter>
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>

void Html::draw(QPainter &painter) const
{
    painter.translate(QPoint(x(),y()));
    QTextDocument td;
    td.setTextWidth(width());
    td.setHtml(text());
    td.drawContents(&painter,QRect(0, 0, width(), height()));
//    QAbstractTextDocumentLayout::PaintContext ctx;
//    ctx.clip = QRect(0, 0, width(), height());
//    td.documentLayout()->draw(&painter, ctx);
    painter.translate(QPoint(-x(),-y()));
}
