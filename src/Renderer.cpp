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

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        stbi_set_flip_vertically_on_load(true);

        int width, height, nrChannels;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        unsigned char *data = stbi_load("../assets/textures/place_holder.png", &width, &height, &nrChannels, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);

        textureBatch = new TextureBatch();
        textureBatch->Init();
        updateOrthoMatrix(1024, 768);
}
void Renderer::RenderQuad(const glm::vec2& position, const glm::vec2& size)
{
        CheckGLError();
        textureBatch->BeginBatch();
        textureBatch->DrawQuad(position, size, texture);
        textureBatch->EndBatch();

        textureBatch->Flush();
}


void Renderer::updateOrthoMatrix(int w, int h)
{
        float width = float(w);
        float height = float(h);
        float ar = width / height;
        float half_width = (1000 * ar) / 2;
        glm::mat4 view = glm::lookAt(glm::vec3(0,0,0), glm::vec3(0,0,-1), glm::vec3(0,1,0));
        glm::mat4 projection = glm::ortho(-half_width, half_width, -500.0f, 500.0f);
        glm::mat4 vp = projection * view;
        textureBatch->SetViewMatrix(vp);
        glViewport(0, 0, width, height);
        // std::cout << orthoMatrix[0][0] << std::endl;
        // orthoMatrix = glm::scale(glm::ortho(0.0f, float(w), 0.0f, float(h)), glm::vec3(scale, scale, scale));

// y = 1000
// dy=k/dx
}
