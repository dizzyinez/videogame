#ifndef RenderEvent_hpp
#define RenderEvent_hpp

#include "entityx/entityx.h"

struct RenderEvent : entityx::Event<RenderEvent>
{
        entityx::Entity::Id id;
};

#endif
