#include <iostream>
#include "States/state.hpp"
#include "game.hpp"
#include "States/StateMainMenu.hpp"

const int FPS_CAP = 60;
const int TICKS_PER_FRAME = 1000 / FPS_CAP;

Game *game = nullptr;
Uint32 startFrame;
float deltaTime;
int main ( int argc, char *argv[])
{
        game = new Game();
        if (game->Init())
        {
                game->pushState(new StateMainMenu());
                startFrame = SDL_GetTicks();
                while (game->running)           // TODO: FIXED UPDATES
                {
                        deltaTime = SDL_GetTicks() - startFrame;
                        if (deltaTime > TICKS_PER_FRAME )
                        {

                                startFrame = SDL_GetTicks();
                                game->HandleEvents();
                                game->Update(deltaTime);
                                game->Render(deltaTime); //does this need deltatime??????
                        }
                }
                game->Clean();
                std::cout << "game exited" << std::endl;
        }
        return 0;
}
