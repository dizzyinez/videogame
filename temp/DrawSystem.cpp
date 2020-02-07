#include "systems/DrawSystem.hpp"

#include "components/Drawable.hpp"
#include "components/Transform.hpp"
#include "components/Texture.hpp"
#include <SDL2/SDL.h>

#include "Locator.hpp"
#include <iostream>

bool sortinrev(const std::pair<int,int> &a,
               const std::pair<int,int> &b)
{
        return (a.first > b.first);
}

void DrawSystem::update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
{
        std::vector<std::vector<std::pair<int, entityx::Entity> > > v(1);
        //v.push_back(new std::vector<std::pair<entityx::Entity, int> >);
        //TODO::push_back layers for each vector (maybe check if it's there yet??)
        // es.each<Drawable>([](Entity entity, Drawable &drawable) {
        // });
        for (auto entity : es.entities_with_components<Drawable, Transform>())
        {
                entityx::ComponentHandle<Drawable> drawable = entity.component<Drawable>();
                entityx::ComponentHandle<Transform> transform = entity.component<Transform>();
                if (drawable && transform) {
                        //TODO: check for rotation and use rendercopyex for that
                        v[drawable->layer].push_back(std::make_pair(transform->getY(), entity));//add height to pos
                }
        }
        sort(v[0].begin(), v[0].end(), sortinrev);
        std::vector<std::vector<std::pair<int, entityx::Entity> > >::iterator layer;
        std::vector<std::pair<int, entityx::Entity> >::iterator pair;

        for ( layer = v.begin(); layer != v.end(); ++layer)
        {
                for (pair = layer->begin(); pair != layer->end(); ++pair)
                {
                        entityx::ComponentHandle<Transform> transform = pair->second.component<Transform>();

                        entityx::ComponentHandle<Texture> texture = pair->second.component<Texture>();
                        if (texture)
                        {

                                SDL_Rect dest;
                                //use position
                                dest.x = transform->getX();
                                dest.w = texture->from.w;

                                dest.h = texture->from.h;
                                dest.y = transform->getY() - dest.h;//add height thing and scale from height
                                Locator::getTexureAllocator()->RenderCopy(*texture->tex.get(), &texture->from, &dest);
                        }
                }
        }
}
