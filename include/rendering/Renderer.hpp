#ifndef Renderer_hpp
#define Renderer_hpp

#include <glm/glm.hpp>
#include "Shader.hpp"
#include "rendering/Batch.hpp"

class Renderer
{
public:
Renderer();
void Init();

// void Render3DQuad

void RenderQuad();
void updateOrthoMatrix(int w, int h);
private:

Batch* batch;


glm::mat4 orthoMatrix;
unsigned int orthoMatrixID;

unsigned int vertexarrayid;
Shader basic_shader;
unsigned int quad_position_buffer;
unsigned int quad_element_buffer;
unsigned int texture;
unsigned int texture_n;

float QuadPositions[20] =
{
        -500.0f, -500.0f, 0.0f,  0.0f,  0.0f,
        500.0f,  -500.0f, 0.0f,  1.0f,  0.0f,
        500.0f,   500.0f, 0.0f,  1.0f,  1.0f,
        -500.0f,  500.0f, 0.0f,  0.0f,  1.0f
};

unsigned int QuadIndices[6] =
{
        0, 1, 2,
        2, 3, 0
};
};

#endif
