#ifndef GUIElement_hpp
#define GUIElement_hpp
#include "entityx/entityx.h"
#include "rhea/variable.hpp"

struct GUIElement : entityx::Component<GUIElement>
{
public:
        rhea::variable x, y, w, h;
};

#endif

/*
   hotbar panel:
   20px from bottom

   n hotbar elements:
   centered vertically

   1/n of the x size

 */
