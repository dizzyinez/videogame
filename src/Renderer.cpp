#include "Renderer.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include "shader.hpp"
#include "CheckGLError.hpp"

Renderer::Renderer()
{

}
void Renderer::Init()
{
        // QuadPositions
        //
        // QuadIndices

        glBindVertexArray(0);
        glGenVertexArrays(1, &vertexarrayid);
        glBindVertexArray(vertexarrayid);

        basic_shader = LoadShaders( "../assets/shaders/basicvert.vshader", "../assets/shaders/basicfrag.fshader" );

        glGenBuffers(1, &quad_position_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, quad_position_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(QuadPositions), QuadPositions, GL_STATIC_DRAW);

        // glEnableVertexAttribArray(0);
        // glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        glGenBuffers(1, &quad_element_buffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad_element_buffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), QuadIndices, GL_STATIC_DRAW);
}
void Renderer::RenderQuad()
{
        glUseProgram(basic_shader);
        // 1st attribute buffer : vertices
        glBindVertexArray(vertexarrayid);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, quad_position_buffer);
        glVertexAttribPointer(
                0,             // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,             // size
                GL_FLOAT,      // type
                GL_FALSE,      // normalized?
                sizeof(float) *3,             // stride
                (void*)0       // array buffer offset
                );
        CheckGLError();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad_element_buffer);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
        // glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices)
        // std::cout << glGetError() << std::endl;
        // glDisableVertexAttribArray(0);
}
