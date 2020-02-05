#ifndef InputEvent_hpp
#define InputEvent_hpp

#include "entityx/entityx.h"
#include <SDL2/SDL.h>

struct InputEvent : entityx::Event<InputEvent>
{
        SDL_Event e_;
        InputEvent(SDL_Event e) : e_(e){
        }
};

#endif
