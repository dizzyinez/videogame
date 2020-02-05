#include "States/StateMainMenu.hpp"
#include <iostream>
#include "ResourceAllocator.hpp"
#include "Locator.hpp"

#include "systems/InputSystem.hpp"
#include "systems/DrawSystem.hpp"
#include "systems/MovementSystem.hpp"

#include "components/Transform.hpp"
#include "components/Velocity.hpp"
#include "components/Texture.hpp"
#include "components/Drawable.hpp"
#include "components/Child.hpp"


void StateMainMenu::init()
{
        systems.add<InputSystem>();
        systems.add<MovementSystem>();
        systems.add<DrawSystem>();
        systems.configure();
        configure(this->events);

        entityx::Entity gamer = entities.create();
        gamer.assign<Transform>(1.0f, 2.0f);
        gamer.assign<Drawable>();
        gamer.assign<Velocity>(0.0f,1.0f);
        gamer.assign<Texture>("../assets/textures/test.png");

}
void StateMainMenu::handleEvents(SDL_Event e)
{
        switch (e.type) {
        case SDL_TEXTINPUT:
                std::cout << e.text.text << std::endl;
                break;
        }
}
void StateMainMenu::update(float deltaTime)
{
        systems.update<InputSystem>(deltaTime);
        systems.update<MovementSystem>(deltaTime);
}
void StateMainMenu::render(float deltaTime)
{
        systems.update<DrawSystem>(deltaTime);
}
void StateMainMenu::clean()
{

}

StateMainMenu::StateMainMenu()
{

}

void StateMainMenu::receive(const InputEvent &input)
{
        switch (input.e_.type) {
        case SDL_QUIT:
                break;
        }
}
