#ifndef MODEHANDLERGLOBAL_H
#define MODEHANDLERGLOBAL_H

#include <vector>
#include "Controller/modehandlerdraw.h"
#include "Controller/modehandleredition.h"

class ModeHandlerGlobal
{
public:
   ModeHandlerGlobal();

   void prepare_edition();

   template<class GraphicObject_>
   void prepare_draw() {
      mode_ = Mode::draw;
      draw_mode_.prepare_draw(std::make_unique<GraphicObject_>());
   }

   void paint(QPainter& painter);

   void mousePressed(int x, int y);
   void mouseMoved(int x, int y);
   void mouseReleased();
   const std::vector<std::unique_ptr<GraphicObject>>& listGraphicObjects() const;

private:
   enum class Mode{
      edition, draw
   };

   std::vector<std::unique_ptr<GraphicObject>> listGraphicObjects_;
   Mode mode_ = Mode::edition;
   ModeHandlerDraw draw_mode_;
   ModeHandlerEdition edition_mode_;

   using Point = std::pair<int, int>;
   Point last_mouse_position;
};

#endif // MODEHANDLERGLOBAL_H
