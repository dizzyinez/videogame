#include "systems/InputSystem.hpp"
#include <iostream>
#include "Locator.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "events/ActionEvent.hpp"

void InputSystem::configure(entityx::EventManager &event_manager)
{

}

void InputSystem::update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
{
        std::vector<Input>* inputs = Locator::getInputHandler()->GetInputs();
        for (std::vector<Input>::iterator it = inputs->begin(); it != inputs->end(); ++it)
        {
                std::cout << it->vector.y << std::endl;
        }
        Locator::getInputHandler()->ClearInputs();
}
