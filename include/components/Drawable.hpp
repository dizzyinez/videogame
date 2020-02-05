#ifndef  Drawable_hpp
#define  Drawable_hpp

#include "entityx/entityx.h"

struct Drawable : entityx::Component<Drawable>
{
public:
        Drawable() : layer(0)
        {
        }
        Drawable(int l) : layer(l)
        {
        }
        int layer; //use enums?

};

#endif
