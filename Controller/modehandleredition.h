#ifndef MODEHANDLEREDITION_H
#define MODEHANDLEREDITION_H
#include <vector>
#include <memory>
#include "Graphics/graphicobject.h"


class ModeHandlerEdition
{
public:

   ModeHandlerEdition(std::vector<std::unique_ptr<GraphicObject>>& listGraphicObjects);

   void mousePressed(int x, int y);
   void mouseMoved(int dx, int dy);
   void mouseReleased();

private:
   enum class Mode{
      idle, object_selected
   };

   std::vector<std::unique_ptr<GraphicObject>>& listGraphicObjects_;
   Mode mode_ = Mode::idle;
   GraphicObject* selectedObject_ = nullptr;
};

#endif // MODEHANDLEREDITION_H
