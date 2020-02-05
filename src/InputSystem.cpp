#include "systems/InputSystem.hpp"
#include <SDL2/SDL.h>
#include "events/InputEvent.hpp"



void InputSystem::update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
{
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
                events.emit<InputEvent>(e);
        }
}
