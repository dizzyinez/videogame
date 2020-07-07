#include "systems/GuiSystem.hpp"

#include "components/Size.hpp"
#include "components/Transform.hpp"
#include "components/Drawable.hpp"
#include "components/GUIElement.hpp"
// #include "components/Texture.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Locator.hpp"
#include <iostream>

#include "rhea/simplex_solver.hpp"

void GuiSystem::update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
{
        for (auto entity : es.entities_with_components<GUIElement, Size, Transform>())
        {
                entityx::ComponentHandle<GUIElement> gui = entity.component<GUIElement>();
                entityx::ComponentHandle<Size> size = entity.component<Size>();
                entityx::ComponentHandle<Transform> transform = entity.component<Transform>();
                entityx::ComponentHandle<Drawable> drawable = entity.component<Drawable>();
                if (gui && size && transform) {
                        transform->setX(gui->x.value());
                        transform->setY(gui->y.value());
                        size->setW(gui->w.value());
                        size->setH(gui->h.value());
                }
                if (drawable)
                {
                        drawable->layer = Layer::gui; //maybe one isn't the best choice for the gui layer
                }
        }
        //loop through gui components
        //find hotbar entity
        //for every item in the hotbar, draw the rectangle and the item

        rhea::simplex_solver solver;
        rhea::variable left, middle, right;
        //
        solver.add_constraints({
                middle == (left + right) / 2,
                right == left + 10,
                right <= 100,
                left >= 0
        });
        solver.suggest(middle, 20);
        // std::cout << left << std::endl;
        // delete &left;
        // std::cout << middle.value() << " " << right.value() << std::endl;

}
