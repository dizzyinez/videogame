#ifndef Batch_hpp
#define Batch_hpp
#include "rendering/Shader.hpp"
#include <glm/glm.hpp>

// struct Quad
// {
//         float x;
//         float y;
//         float z;
//
//         float texture;
//
// };

struct Vertex
{
        glm::vec3 position;
        //float color[3];
        glm::vec2 texCoords;
        //float texture;
};


// template <typename T>
class Batch
{
public:
void Init();

void BeginBatch();
void EndBatch();
void DrawQuad(const glm::vec2& position, const glm::vec2& size);
//TODO: void DrawRotatedQuad();
void Flush(); //virtual?

void Clean();
private:
size_t MaxQuadCount;// = 5000;
size_t MaxVertexCount;// = MaxQuadCount * 4;
size_t MaxIndexCount;// = MaxQuadCount * 6;
size_t MaxTextures = 32;

unsigned int QuadVA = 0;
unsigned int QuadVB = 0;
unsigned int QuadIB = 0;

unsigned int WhiteTexture = 0;
uint32_t WhiteTextureSlot = 0;

uint32_t IndexCount = 0;

Vertex* QuadBuffer = nullptr;
Vertex* QuadBufferPtr = nullptr;

Shader shader;
};

#endif
