#ifndef Size_hpp
#define Size_hpp
#include "entityx/entityx.h"
#include <glm/vec3.hpp>

struct Size : entityx::Component<Size>
{
        //add a scale value?
        glm::vec3 size;
        Transform(float x = 0, float y = 0) : size(x,y,0.0f){
        }
        Transform(glm::vec3 pos) : size(pos){
        }

        float getX()
        {
                return size.x;
        }

        float getY()
        {
                return size.y;
        }

        void setX(float x)
        {
                size.x = x;
        }

        void setY(float y)
        {
                size.y = y;
        }

        //make add functions
};

#endif
