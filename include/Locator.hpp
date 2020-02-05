#ifndef Locator_hpp
#define Locator_hpp

#include "ResourceAllocator.hpp"
#include "TextureAllocator.hpp"
#include <SDL2/SDL.h>

class Locator
{
public:
static void Initialize() {
}
static TextureAllocator* getTexureAllocator() {
        return &TA;
}
static void provideRenderer(SDL_Renderer* r)
{
        TA.setRenderer(r);
}
static void provideWindow(SDL_Window* w)
{
        TA.setWindow(w);
}
private:
static TextureAllocator TA;
};

#endif
