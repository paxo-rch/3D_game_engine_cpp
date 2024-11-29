#include "3d.hpp"
#include "engine.hpp"
#include <iostream>

Object::~Object()
{
    for (Object* o : children)
    {
        delete o;
    }
}

void Object::renderAll(View& view)
{
    render(view);

    for (Object* o : children)
    {
        o->renderAll(view);
    }
}

Engine::Engine()
{
    /*for (int i = 0; i < 24; i++)
    {
        thread[i] = std::thread([&](Engine* e) {
            while (true)
            {
                for (int i = 0; i < 24; i++)
                {
                    if(e->thread_objects[i] != nullptr)
                    {
                        e->thread_objects[i]->renderAll(e->thread_objects[i]->v);
                        e->thread_objects[i] = nullptr;
                    }
                }
            }
        }, this);
    }*/
}

Engine::~Engine()
{
    for (Object* o : objects)
    {
        delete o;
    }
}