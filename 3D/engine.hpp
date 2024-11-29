#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "3d.hpp"
#include <thread>

class Object
{
    public:
        virtual void render(View& view) {};
        void renderAll(View& view);
        ~Object();

        double x, y, z, rx, ry, rz = 0;
        std::vector<Object*> children;
};

class Engine
{
    public:
        Engine();
        ~Engine();
    
        std::vector<Object*> objects;
        //View& view;
        
        Object* thread_objects[24] = {nullptr};
        std::thread thread[24];
};

#endif