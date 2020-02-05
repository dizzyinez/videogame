#ifndef Transform_hpp
#define Transform_hpp

#include "entityx/entityx.h"
#include "vec2.hpp"

struct Transform : entityx::Component<Transform>
{
        vec2f position;
        float height;
        Transform(float x = 0, float y = 0) : height(0) {
                position.x = x;
                position.y = y;
        }
        Transform(vec2f pos) : position(pos), height(0) {
        }
        Transform(vec2f pos, float h = 0) : position(pos), height(h) {
        }

        float getX()
        {
                return position.x;
        }

        float getY()
        {
                return position.y;
        }

        void setX(float x)
        {
                position.x = x;
        }

        void setY(float y)
        {
                position.y = y;
        }

        //make add functions
};

#endif
