#ifndef StateMainMenu_hpp
#define StateMainMenu_hpp

#include "state.hpp"
#include "entityx/entityx.h"
#include "events/InputEvent.hpp"

class StateMainMenu : public State, public entityx::EntityX, public entityx::Receiver<StateMainMenu>
{
public:
void init();
void handleEvents(SDL_Event e);
void update(float deltaTimeq);
void render(float deltaTime);
void clean();
StateMainMenu();//pass through game*

void configure(entityx::EventManager &event_manager)
{
        event_manager.subscribe<InputEvent>(*this);
}

void receive(const InputEvent &input);

private:
//std::shared_ptr<Object> player;
};

#endif
