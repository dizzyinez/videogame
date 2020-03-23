#include "InputHandler.hpp"
#include "events/ActionEvent.hpp"
#include "Locator.hpp"

/*
   TODO:
   send typing events
   send action button events
 */

std::vector<Input> inputs;

void window_size_callback(GLFWwindow* window, int width, int height)
{
        Locator::getRenderer()->updateOrthoMatrix(width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
        inputs.emplace_back(Input(Action::MOTION, Press::NONE, glm::vec2(1.0f,0.0f)));
}

std::vector<Input>* InputHandler::GetInputs()
{
        return &inputs;
}

void InputHandler::ClearInputs()
{
        inputs.clear();
}

InputHandler::InputHandler()
{

}

void InputHandler::Init()
{
        glfwSetWindowSizeCallback(window, window_size_callback);
        glfwSetKeyCallback(window, key_callback);
}
