#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <vector>
#include <stack>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include "state.h"

class State;

class Game {
public:
bool running;

Game();
~Game();
bool Init();
void HandleEvents();
void Update(float deltaTime);
void Render(float deltaTime);
void Clean();

// states
std::stack<State*> states;

void pushState(State* state);
void popState();
void changeState(State* state);
State* peekState();

SDL_Renderer* getRenderer();
private:
static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Event event;
static std::vector<SDL_Event> events;
};

#endif
