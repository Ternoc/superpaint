#ifndef SUPERPAINTWIDGET_H
#define SUPERPAINTWIDGET_H

#include <QWidget>
#include <vector>
#include <memory>
#include "Graphics/graphicobject.h"
#include "Controller/modehandlerglobal.h"


namespace Ui {
class SuperPaintWidget;
}

class SuperPaintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SuperPaintWidget(QWidget *parent = 0);
    ~SuperPaintWidget();

public slots:
    void button_selection_clicked();
    void button_rect_clicked();
    void button_text_clicked();
    void button_html_clicked();
    void button_line_clicked();
    void button_arrow_directed_clicked();
    void button_ellipse_clicked();

private:
    Ui::SuperPaintWidget *ui;
    ModeHandlerGlobal global_mode_;

protected:
    virtual void paintEvent(QPaintEvent *) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *) override;
};

#endif // SUPERPAINTWIDGET_H
