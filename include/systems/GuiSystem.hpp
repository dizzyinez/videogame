#ifndef GuiSystem_hpp
#define GuiSystem_hpp

#include "entityx/entityx.h"
struct GuiSystem : public entityx::System<GuiSystem>
{
public:
        void update(entityx::EntityManager &es, entityx::EventManager &events, double dt) override;
};

#endif
