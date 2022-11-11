#ifndef TEXT_H
#define TEXT_H
#include "abstractrectangle.h"
#include <QString>

class Text : public AbstractRectangle
{
public:
    void draw(QPainter &painter) const override;
    void set_text(const QString &user_text);
protected:
    const QString& text() const;
private:
    QString text_ =  "Le vif zephyr <b>jubile</b> sous les cumquats du clown gracieux \n(avec ses gros globules glabres)";
};

#endif // TEXT_H
