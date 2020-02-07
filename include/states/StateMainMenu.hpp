#ifndef StateMainMenu_hpp
#define StateMainMenu_hpp

#include "state.hpp"
#include "entityx/entityx.h"

class StateMainMenu : public State, public entityx::EntityX
{
public:
void init();
void handleEvents();
void update(float deltaTimeq);
void render(float deltaTime);
void clean();
StateMainMenu();//pass through game

private:
//std::shared_ptr<Object> player;
};

#endif
