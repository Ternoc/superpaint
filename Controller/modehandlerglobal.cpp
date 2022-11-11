#include "modehandlerglobal.h"

void ModeHandlerGlobal::prepare_edition()
{
    mode_ = Mode::edition;
}

void ModeHandlerGlobal::paint(QPainter &painter)
{
    if (mode_==Mode::edition) {
        //do something
    }
    else if (mode_==Mode::draw) {
        draw_mode_.paint_object(painter);
    }
}

void ModeHandlerGlobal::mousePressed(int x, int y)
{
    if (mode_==Mode::edition) {
        //do something
    }
    else if (mode_==Mode::draw) {
        draw_mode_.start_drawing(x,y);
    }
}

void ModeHandlerGlobal::mouseMoved(int x, int y)
{
    if (mode_==Mode::edition) {
        //do something
    }
    else if (mode_==Mode::draw) {
        draw_mode_.keep_drawing(x,y);
    }
}

void ModeHandlerGlobal::mouseReleased(std::vector<std::unique_ptr<GraphicObject> > &listGraphicObjects)
{
    if (mode_==Mode::edition) {
        //do something
    }
    else if (mode_==Mode::draw) {
        auto just_drawn_object = draw_mode_.stop_drawing();
        if (just_drawn_object)
            listGraphicObjects.emplace_back(std::move(just_drawn_object));
    }
}
