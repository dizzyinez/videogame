#ifndef Locator_hpp
#define Locator_hpp

#include "ResourceAllocator.hpp"
#include "rendering/Renderer.hpp"
// #include "TextureAllocator.hpp"

class Locator
{
public:
static void Initialize() {
        R.Init();
}
static Renderer* getRenderer()
{
        return &R;
}
// static TextureAllocator* getTexureAllocator() {
//         return &TA;
// }
// static void provideWindow(GLFWwindow* w)
// {
//         // TA.setWindow(w);
// }
private:
static Renderer R;
// static TextureAllocator TA;
};

#endif
