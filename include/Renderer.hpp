#ifndef Renderer_hpp
#define Renderer_hpp

class Renderer
{
public:
Renderer();
void Init();
void RenderQuad();
private:
unsigned int vertexarrayid;
unsigned int basic_shader;
unsigned int quad_position_buffer;
unsigned int quad_element_buffer;
float QuadPositions[12] =
{
        -0.5f, -0.5f, 0.0f,
        0.5f,  -0.5f, 0.0f,
        0.5f,   0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
};

unsigned int QuadIndices[6] =
{
        0, 1, 2,
        2, 3, 0
};
};

#endif
