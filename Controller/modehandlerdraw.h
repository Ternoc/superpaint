#ifndef DRAWMODEHANDLER_H
#define DRAWMODEHANDLER_H

#include "Graphics/graphicobject.h"
#include <memory>

class ModeHandlerDraw
{
public:
    void prepare_draw(std::unique_ptr<GraphicObject> g);

    void start_drawing(int x, int y);
    void keep_drawing(int x, int y);
    std::unique_ptr<GraphicObject> stop_drawing();

    void paint_object(QPainter& painter) const;

private:
    enum class Mode{
        idle, preparation, drawing
    };

    Mode mode_ = Mode::idle;
    std::unique_ptr<GraphicObject> object_;
};

#endif // DRAWMODEHANDLER_H
