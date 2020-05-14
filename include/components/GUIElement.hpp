#ifndef GUIElement_hpp
#define GUIElement_hpp
#include "entityx/entityx.h"

struct Constraint
{
        virtual float value(float input);
};

struct Constraint_Center : Constraint
{
        float value(float input)
        {
                return input / 2.0f;
        }
};

struct Constraint_Margin_Min : Constraint
{

};
struct Constraint_Margin_Max : Constraint
{

};
struct Constraint_Margin_Double : Constraint
{
//size Constraint
};

struct GUIElement : entityx::Component<GUIElement>
{
public:

};

#endif
