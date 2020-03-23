#ifndef Locator_hpp
#define Locator_hpp

#include "ResourceAllocator.hpp"
#include "rendering/Renderer.hpp"
#include "InputHandler.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
// #include "TextureAllocator.hpp"

class Locator
{
public:
static void Initialize() {
        R.Init();
        IH.Init();
}
static void provideWindow(GLFWwindow* w)
{
        window = w;
        IH.provideWindow(w);
}

static Renderer* getRenderer()
{
        return &R;
}

static InputHandler* getInputHandler()
{
        return &IH;
}

static GLFWwindow* getWindow()
{
        return window;
}
private:
static Renderer R;
static InputHandler IH;
static GLFWwindow* window;
// static TextureAllocator TA;
};

#endif
