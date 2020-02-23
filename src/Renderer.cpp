#include "rendering/Renderer.hpp"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include "CheckGLError.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "rendering/loadShader.hpp"



struct Vertexd
{
        float position[3];
        float texCoords[2];
};


Renderer::Renderer()
{

}
void Renderer::Init()
{
        batch = new Batch();
        batch->Init();

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        stbi_set_flip_vertically_on_load(true);

        updateOrthoMatrix(1024, 768);
        basic_shader.Load("../assets/shaders/basicvert.vshader", "../assets/shaders/basicfrag.fshader");
        orthoMatrixID = basic_shader.GetUniformLocation("ortho");


        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        int width, height, nrChannels;
        unsigned char *data = stbi_load("../assets/textures/place_holder.png", &width, &height, &nrChannels, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);

        glGenTextures(1, &texture_n);
        glBindTexture(GL_TEXTURE_2D, texture_n);
        data = stbi_load("../assets/textures/place_holder_normals.png", &width, &height, &nrChannels, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);


        glGenVertexArrays(1, &vertexarrayid);
        glBindVertexArray(vertexarrayid);


        glCreateBuffers(1, &quad_position_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, quad_position_buffer);
        glBufferData(GL_ARRAY_BUFFER, 600 * 4 * sizeof(Vertexd), nullptr, GL_DYNAMIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertexd), (const void*)offsetof(Vertexd, position));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertexd), (const void*)offsetof(Vertexd, texCoords));

        glCreateBuffers(1, &quad_element_buffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad_element_buffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), QuadIndices, GL_STATIC_DRAW);

        basic_shader.Bind();
        glUniformMatrix4fv(basic_shader.GetUniformLocation("ortho"), 1, GL_FALSE, &orthoMatrix[0][0]);
        glUniform1i(basic_shader.GetUniformLocation("image1"), 0);
        glUniform1i(basic_shader.GetUniformLocation("image2"), 1);
}
void Renderer::RenderQuad()
{
        CheckGLError();
        batch->BeginBatch();
        batch->DrawQuad(glm::vec2(0.0f, 0.0f), glm::vec2(600.0f, 600.0f));
        batch->EndBatch();

        basic_shader.Bind();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture_n);

        batch->Flush();
        // glBindBuffer(GL_ARRAY_BUFFER, quad_position_buffer);
        // glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(QuadPositions), QuadPositions);
        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad_element_buffer);
        //
        // // glUseProgram(basic_shader);
        //
        glBindVertexArray(vertexarrayid);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
}


void Renderer::updateOrthoMatrix(int w, int h)
{
        float x_scale = w*float(500.0f/float(h));
        orthoMatrix = glm::ortho(-x_scale, x_scale, -500.0f, 500.0f);
        // orthoMatrix = glm::scale(glm::ortho(0.0f, float(w), 0.0f, float(h)), glm::vec3(scale, scale, scale));


}
