// #include "systems/Mov.hpp"

#include "components/Transform.hpp"
#include "components/Velocity.hpp"

//#include "vec2.hpp "

void MovementSystem::update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
{
        // std::cout << "wow" << std::endl;
        // for (auto entity : es.entities_with_components<Transform, Velocity>())
        // {
        //         entityx::ComponentHandle<Transform> transform = entity.component<Transform>();
        //         entityx::ComponentHandle<Velocity> velocity = entity.component<Velocity>();
        //         if (transform && velocity)
        //         {
        //                 //transform.position += velocity.vel;
        //         }
        // }
}
