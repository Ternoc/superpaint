#include "modehandlerdraw.h"

using namespace std;

void ModeHandlerDraw::prepare_draw(unique_ptr<GraphicObject> g)
{
    object_ = std::move(g);
    mode_ = Mode::preparation;
}

void ModeHandlerDraw::start_drawing(int x, int y)
{
    if (mode_!=Mode::preparation)
        return;

    mode_ = Mode::drawing;
    object_->set_initial_position(x,y);
}

void ModeHandlerDraw::keep_drawing(int x, int y)
{
    if (mode_!=Mode::drawing)
        return;

    object_->set_extents(x,y);
}

unique_ptr<GraphicObject> ModeHandlerDraw::stop_drawing()
{
    if (mode_==Mode::drawing)
    {
        mode_ = Mode::idle; //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% EN VEUT METTRE PREPARATION (methode clone ?)
    }
    return std::move(object_);
}

void ModeHandlerDraw::paint_object(QPainter &painter) const
{
    if (object_)
        object_->draw(painter);
}
