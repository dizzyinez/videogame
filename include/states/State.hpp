#ifndef State_hpp
#define State_hpp

//#include "game.h"

class Game;

class State
{
public:

Game* game;

virtual void init() {
};
virtual void handleEvents() {
};
virtual void update(float deltaTime) {
};
virtual void render(float deltaTime) {
};
virtual void clean() {
};
};

#endif
