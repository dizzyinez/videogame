#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>

// #include "CheckGLError.hpp"

#include "game.hpp"
#include "States/StateMainMenu.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;


const int UPDATE_RATE = 60;
const int SECONDS_PER_UPDATE = 1 / UPDATE_RATE;
Game *game = nullptr;
int main()
{
        glewExperimental = true;
        if (!glfwInit())
        {
                std::cout << "Failed to initialise GLFW" << std::endl;
                return 1;
        }

        glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

        GLFWwindow* window = glfwCreateWindow( 1024, 768, "VideoGame", NULL, NULL);
        if( !window ) {
                std::cout << "Failed to open GLFW window." << std::endl;
                glfwTerminate();
                return 1;
        }
        glfwMakeContextCurrent(window); // Initialize GLEW
        glewExperimental=true; // Needed in core profile
        if (glewInit() != GLEW_OK) {
                std::cout << "Failed to initialise GLEW" << std::endl;
                return 1;
        }

        std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
        std::cout << "OpenGL Version supported:  " << glGetString(GL_VERSION) << std::endl;
        int tu = 0;
        glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &tu);
        std::cout << "Maximum Texture Units: " << tu << std::endl;

        // Dark blue background
        glClearColor(0.0f, 0.0f, 0.3f, 0.0f);


        //
        // // Get a handle for our "MVP" uniform
        // GLuint MatrixID = glGetUniformLocation(programID, "MVP");
        //
        // // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
        // glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        // // Camera matrix
        // glm::mat4 View       = glm::lookAt(
        //         glm::vec3(4,3,3),         // Camera is at (4,3,3), in World Space
        //         glm::vec3(0,0,0),         // and looks at the origin
        //         glm::vec3(0,1,0)          // Head is up (set to 0,-1,0 to look upside-down)
        //         );
        // // Model matrix : an identity matrix (model will be at the origin)
        // glm::mat4 Model      = glm::mat4(1.0f);
        // // Our ModelViewProjection : multiplication of our 3 matrices
        // glm::mat4 MVP        = Projection * View * Model;   // Remember, matrix multiplication is the other way around
        //

        game = new Game();
        if (game->Init(window))
        {
                game->pushState(new StateMainMenu());
                double deltaTime;
                // CheckGLError();
                while (game->running && !glfwWindowShouldClose(window))           // TODO: FIXED UPDATES
                {
                        glClear( GL_COLOR_BUFFER_BIT);

                        deltaTime = glfwGetTime();
                        if (deltaTime > SECONDS_PER_UPDATE )
                        {
                                glfwSetTime(0);
                                game->HandleEvents();
                                game->Update(deltaTime);
                        }
                        game->Render(deltaTime);

                        // glUseProgram(programID);

                        // // Send our transformation to the currently bound shader,
                        // // in the "MVP" uniform
                        // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

                        // // 1st attribute buffer : vertices
                        // glBindVertexArray(VertexArrayID);
                        // glEnableVertexAttribArray(0);
                        // glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
                        // glVertexAttribPointer(
                        //         0,             // attribute 0. No particular reason for 0, but must match the layout in the shader.
                        //         3,             // size
                        //         GL_FLOAT,      // type
                        //         GL_FALSE,      // normalized?
                        //         sizeof(float) *3,             // stride
                        //         (void*)0       // array buffer offset
                        //         );
                        // CheckGLError();
                        // // Draw the triangle !
                        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
                        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0); // Starting from vertex 0; 3 vertices total -> 1 triangle
                        // glDisableVertexAttribArray(0);
                        glfwSwapBuffers(window);
                        glfwPollEvents();

                }
                game->Clean();
                std::cout << "game exited" << std::endl;
        }
        else
        {
                std::cout << "Failed to initialise the Game" << std::endl;
        }
        glfwTerminate();
        return 0;
}
