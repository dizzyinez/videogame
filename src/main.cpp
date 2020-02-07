#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>

#include "game.hpp"
#include "States/StateMainMenu.hpp"

const int UPDATE_RATE = 60;
const int SECONDS_PER_UPDATE = 1 / UPDATE_RATE;

Game *game = nullptr;
int main()
{
        glewExperimental = true;
        if (!glfwInit())
        {
                std::cout << "Failed to initialise GLFW" << std::endl;
                return -1;
        }

        glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

        GLFWwindow* window;
        window = glfwCreateWindow( 1024, 768, "VideoGame", NULL, NULL);
        if( window == NULL ) {
                std::cout << "Failed to open GLFW window." << std::endl;
                glfwTerminate();
                return -1;
        }
        glfwMakeContextCurrent(window); // Initialize GLEW
        glewExperimental=true; // Needed in core profile
        if (glewInit() != GLEW_OK) {
                std::cout << "Failed to initialise GLEW" << std::endl;
                return -1;
        }

        game = new Game();
        if (game->Init(window))
        {
                game->pushState(new StateMainMenu());
                double deltaTime;
                while (game->running && !glfwWindowShouldClose(window))           // TODO: FIXED UPDATES
                {
                        deltaTime = glfwGetTime();
                        if (deltaTime > SECONDS_PER_UPDATE )
                        {
                                glfwSetTime(0);
                                game->HandleEvents();
                                game->Update(deltaTime);
                                game->Render(deltaTime);
                        }
                }
                game->Clean();
                std::cout << "game exited" << std::endl;
        }
        else
        {
                std::cout << "Failed to initialise the Game" << std::endl;
        }
        return 0;
}
