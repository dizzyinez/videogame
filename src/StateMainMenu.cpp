#include "States/StateMainMenu.hpp"
#include <iostream>

// #include "Locator.hpp"

// #include "systems/InputSystem.hpp"
#include "systems/DrawSystem.hpp"
// #include "systems/MovementSystem.hpp"
//
#include "components/Transform.hpp"
// #include "components/Velocity.hpp"
// #include "components/Texture.hpp"
#include "components/Drawable.hpp"
// #include "components/Child.hpp"
// #include "components/Input_Velocity.hpp"


void StateMainMenu::init()
{
        // systems.add<InputSystem>();
        // systems.add<MovementSystem>();
        systems.add<DrawSystem>();
        systems.configure();
        // configure(this->events);
        //
        entityx::Entity gamer = entities.create();
        gamer.assign<Transform>(1.0f, 2.0f);
        // gamer.assign<Velocity>(0.0f,0.1f);
        // gamer.assign<Input_Velocity>(6);
        gamer.assign<Drawable>();
        // gamer.assign<Texture>("../assets/textures/temp_player.png");

}
void StateMainMenu::handleEvents()
{

}
void StateMainMenu::update(float deltaTime)
{

        // systems.update<InputSystem>(deltaTime);
        // systems.update<MovementSystem>(deltaTime);
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
