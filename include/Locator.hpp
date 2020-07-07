#ifndef Locator_hpp
#define Locator_hpp

#include "ResourceAllocator.hpp"
#include "rendering/Renderer.hpp"
#include "InputHandler.hpp"
#include "rhea/simplex_solver.hpp"

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

static rhea::simplex_solver* getGuiSolver()
{
        return &GUI_S;
}

private:
static Renderer R;
static InputHandler IH;
static GLFWwindow* window;
static rhea::simplex_solver GUI_S;
// static TextureAllocator TA;
};

#endif
