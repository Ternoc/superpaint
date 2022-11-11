#include "modehandlerglobal.h"

ModeHandlerGlobal::ModeHandlerGlobal() : edition_mode_(listGraphicObjects_){
}

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
      edition_mode_.mousePressed(x,y);
   }
   else if (mode_==Mode::draw) {
      draw_mode_.start_drawing(x,y);
   }
}

void ModeHandlerGlobal::mouseMoved(int x, int y)
{
   const auto dx = x - last_mouse_position.first;
   const auto dy = y - last_mouse_position.second;

   if (mode_==Mode::edition) {
      edition_mode_.mouseMoved(dx,dy);
   }
   else if (mode_==Mode::draw) {
      draw_mode_.keep_drawing(x,y);
   }

   last_mouse_position = std::make_pair(x,y);
}

void ModeHandlerGlobal::mouseReleased()
{
   if (mode_==Mode::edition) {
      edition_mode_.mouseReleased();
   }
   else if (mode_==Mode::draw) {
      auto just_drawn_object = draw_mode_.stop_drawing();
      if (just_drawn_object)
         listGraphicObjects_.emplace_back(std::move(just_drawn_object));
      prepare_edition();
   }
}

const std::vector<std::unique_ptr<GraphicObject> > &ModeHandlerGlobal::listGraphicObjects() const
{
   return listGraphicObjects_;
}
