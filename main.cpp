#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "conf.hpp"
#include "3D/3d.hpp"
#include "3D/point.hpp"
#include "events/events_types.hpp"

int main()
{
    View v(-2.36, -0.33, 4.04, 6.343, 1.938, 0);

    Object o;

    /*for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                o.children.push_back(new Point(i, j, k));
            }
        }
    }


    for (int i = 0; i < 360; i+=2)
    {
        for (int k = -180; k < 180; k+=2)
        {
            o.children.push_back(new Point(cos(i * M_PI / 180) * sqrt(1-pow(k * M_PI / 180, 2)), sin(i * M_PI / 180) * sqrt(1-pow(k * M_PI / 180, 2)), k * M_PI / 180));
        }
    }*/

    float s = 0.04;

    for (float i = 0; i < 10; i+=s)
    {
        for (float j = 0; j < 10; j+=s)
        {
            o.children.push_back(new Triangle({i+0, j+0, 0}, {i+s, j+0, 0}, {i+s, j+s, 0}, sf::Color::Red));
            o.children.push_back(new Triangle({i+0, j+0, 0}, {i+0, j+s, 0}, {i+s, j+s, 0}, sf::Color::Blue));
        }
    }

    sf::Vector2i centerPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    v.window.setMouseCursorVisible(false);
    sf::Mouse::setPosition(centerPosition, v.window);

    sf::Clock clock;
    while (v.window.isOpen() || true)
    {
        sf::Event event;


        while (v.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                v.window.close();
            
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(v.window);
                sf::Vector2i delta = mousePos - centerPosition;
                
                if (delta.x != 0 || delta.y != 0)
                {
                    float sensitivity = 0.001f;  // Adjust this value to change mouse sensitivity
                    v.ry -= delta.x * sensitivity;
                    v.rx += delta.y * sensitivity;
                    
                    //if(v.rz != 0 || v.ry != 0)
                        sf::Mouse::setPosition(centerPosition, v.window);
                    
                    std::cout << "Mouse delta: " << delta.x << " " << delta.y << std::endl;
                }
            }
        }


        sf::Time time = clock.restart();

        if (time.asMilliseconds() < 33)
        {
            sf::sleep(sf::milliseconds(33 - time.asMilliseconds()));
        }

        if(keyLeft())
        {
            v.x -= 0.01;
        }

        if(keyRight())
        {
            v.x += 0.01;
        }

        if(keyUp())
        {
            v.y -= 0.01;
        }

        if(keyDown())
        {
            v.y += 0.01;
        }

        if(keyEscape())
        {
            v.z += 0.01;
        }

        if(click())
        {
            v.z -= 0.01;
        }
        
        v.window.clear();
        
        v.update_angles();
        o.renderAll(v);

        v.window.display();
    }

    return 0;
}