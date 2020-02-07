#include "systems/InputSystem.hpp"
#include <SDL2/SDL.h>
#include "events/InputEvent.hpp"
#include "components/Input_Velocity.hpp"



void InputSystem::update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
{
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
                events.emit<InputEvent>(e);
                switch (e.type) {
                case SDL_KEYDOWN:
                        for (auto entity : es.entities_with_components<Input_Velocity>())
                        {
                                entityx::ComponentHandle<Input_Velocity> input_velocity = entity.component<Input_Velocity>();
                                if (input_velocity)
                                {
                                        for (int i = 0; i < input_velocity->keymap.size(); i++)
                                        {
                                                if (e.key.keysym.sym == input_velocity->keymap[i].first)
                                                {
                                                        input_velocity->keymap[i].second = true;
                                                }
                                        }
                                }
                        }
                        break;
                case SDL_KEYUP:
                        for (auto entity : es.entities_with_components<Input_Velocity>())
                        {
                                entityx::ComponentHandle<Input_Velocity> input_velocity = entity.component<Input_Velocity>();
                                if (input_velocity)
                                {
                                        for (int i = 0; i < input_velocity->keymap.size(); i++)
                                        {
                                                if (e.key.keysym.sym == input_velocity->keymap[i].first)
                                                {
                                                        input_velocity->keymap[i].second = false;
                                                }
                                        }
                                }
                        }
                        break;
                }
        }
}
