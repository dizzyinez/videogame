#include "Locator.hpp"

// TextureAllocator Locator::TA = TextureAllocator();
Renderer Locator::R = Renderer();
InputHandler Locator::IH = InputHandler();
GLFWwindow* Locator::window = nullptr;
rhea::simplex_solver Locator::GUI_S;
