#ifndef Velocity_hpp
#define Velocity_hpp

#include "entityx/entityx.h
#include "vec2.hpp "

struct Velocity : entityx::Component<Velocity>
{
        vec2f vel;
        float verticalVel;
        Velocity(float x = 0, float y = 0) : verticalVel(0) {
                vel.x = x;
                vel.y = y;
        }
        Velocity(vec2f v) : vel(v), verticalVel(0) {
        }
        Velocity(vec2f v, float vh = 0) : vel(v), verticalVel(vh) {
        }

        float getX()
        {
                return vel.x;
        }

        float getY()
        {
                return vel.y;
        }

        void setX(float x)
        {
                vel.x = x;
        }

        void setY(float y)
        {
                vel.y = y;
        }
};


#endif
