#include "superpaintwidget.h"
#include "ui_superpaintwidget.h"

#include <QPaintEvent>
#include <QPainter>

#include "Graphics/rectangle.h"
#include "Graphics/text.h"
#include "Graphics/line.h"
#include "Graphics/arrowdirected.h"
#include "Graphics/html.h"
#include "Graphics/ellipse.h"


void SuperPaintWidget::button_selection_clicked()
{
    global_mode_.prepare_edition();
}

void SuperPaintWidget::button_rect_clicked()
{
    global_mode_.prepare_draw<Rectangle>();
}

void SuperPaintWidget::button_text_clicked()
{
   global_mode_.prepare_draw<Text>();
}

void SuperPaintWidget::button_html_clicked()
{
   global_mode_.prepare_draw<Html>();
}

void SuperPaintWidget::button_line_clicked()
{
    global_mode_.prepare_draw<Line>();
}

void SuperPaintWidget::button_arrow_directed_clicked()
{
   global_mode_.prepare_draw<ArrowDirected>();
}

void SuperPaintWidget::button_ellipse_clicked()
{
   global_mode_.prepare_draw<Ellipse>();
}

SuperPaintWidget::SuperPaintWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuperPaintWidget)
{
    ui->setupUi(this);
}

SuperPaintWidget::~SuperPaintWidget()
{
    delete ui;
}

void SuperPaintWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    for (const auto& gobj : listGraphicObjects_)
    {
        gobj->draw(painter); //objects of the list (already stored)
    }
    global_mode_.paint(painter); //object in cours of creation (fucking genius)
}

void SuperPaintWidget::mousePressEvent(QMouseEvent *event)
{
    global_mode_.mousePressed(event->x(), event->y());
    repaint();
}

void SuperPaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    global_mode_.mouseMoved(event->x(), event->y());
    repaint();
}

void SuperPaintWidget::mouseReleaseEvent(QMouseEvent*)
{
    global_mode_.mouseReleased(listGraphicObjects_);
    repaint();
}

