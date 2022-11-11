#include "modehandleredition.h"

ModeHandlerEdition::ModeHandlerEdition(std::vector<std::unique_ptr<GraphicObject> > &listGraphicObjects) : listGraphicObjects_(listGraphicObjects) {

}

void ModeHandlerEdition::mousePressed(int x, int y) {
	for(auto objectIterator = listGraphicObjects_.rbegin() ; objectIterator != listGraphicObjects_.rend() ; ++objectIterator) {
      std::unique_ptr<GraphicObject>& gobj = *objectIterator;
		if(gobj->contains(x,y)) {
			selectedObject_ = gobj.get();
			break;
		}
   }
}

void ModeHandlerEdition::mouseMoved(int dx, int dy)
{
   if(!selectedObject_)
      return;

   selectedObject_->shift_position(dx, dy);
}

void ModeHandlerEdition::mouseReleased()
{
   selectedObject_ = nullptr;
}
