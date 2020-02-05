#include "States/State.hpp"
#include "game.hpp"
//#include "TextureAllocator.hpp"
#include "Locator.hpp"

SDL_Window* Game::window = nullptr;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
std::vector<SDL_Event> Game::events;

Game::Game() {
}

Game::~Game()
{
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        //TTF_Quit();
        //Mix_Quit();
        IMG_Quit();
        SDL_Quit();
        //clear events
}

bool Game::Init()
{
        if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        {
                std::cout << "SDL initialized " << std::endl;

                int flags = SDL_WINDOW_RESIZABLE;

                window = SDL_CreateWindow("td ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, flags);
                renderer = SDL_CreateRenderer(window, -1, 0);
                if (renderer)
                {
                        SDL_SetRenderDrawColor(renderer, 1, 144, 144, 255);
                        running = true;
                }
        }
        else
        {
                std::cout << "SDL could not initialize: " << std::endl;
                running = false;
                return false;
        }

        Locator::provideRenderer(renderer);
        Locator::provideWindow(window);
        Locator::getTexureAllocator()->setWindowIcon("../assets/textures/test.png");
        return true;
}

void Game::HandleEvents()
{
        /*
              events.clear();
              while(SDL_PollEvent(&event))
              {
                      events.push_back(event);
                      switch (event.type)
                      {
                      case SDL_QUIT:
                              running = false;
                              break;
                      default:
                              if (peekState() != nullptr)
                              {
                                      peekState()->handleEvents(event); //pass through events vector
                              }
                      }
              }*/
}

void Game::Update(float deltaTime)
{
        if (peekState() != nullptr)
        {
                peekState()->update(deltaTime);
        }
}

void Game::Render(float deltaTime)
{
        SDL_RenderClear(renderer);
        if (peekState() != nullptr)
        {
                peekState()->render(deltaTime);
        }
//render the current state
        SDL_RenderPresent(renderer);
}

void Game::Clean ()
{

}

void Game::pushState(State* state)
{
        states.push(state);
        state->init();
}

void Game::popState()
{
        peekState()->clean();
        delete states.top();
        states.pop();
}

void Game::changeState(State* state)
{
        if (!states.empty()) popState();
        pushState(state);
}

State* Game::peekState()
{
        if (states.empty()) return nullptr;

        return states.top();
}

SDL_Renderer* Game::getRenderer()
{
        return renderer;
}
