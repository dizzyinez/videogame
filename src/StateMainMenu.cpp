#include "States/StateMainMenu.hpp"
#include <iostream>

void StateMainMenu::init()
{

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

}
void StateMainMenu::render()
{

}
void StateMainMenu::clean()
{

}

StateMainMenu::StateMainMenu()
{

}
