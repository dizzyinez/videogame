#ifndef StateMainMenu_hpp
#define StateMainMenu_hpp

#include "state.hpp"
#include "entityx/entityx.h"

class StateMainMenu : public State, public entityx::EntityX, public entityx::Receiver<InputEvent>
{
public:
void init();
void handleEvents(SDL_Event e);
void update(float deltaTimeq);
void render();
void clean();
StateMainMenu();//pass through game*

void configure(entityx::EventManager &event_manager)
{

}
private:
//std::shared_ptr<Object> player;
};

#endif
