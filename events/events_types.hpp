#ifndef EVENTS_TYPES_HPP
#define EVENTS_TYPES_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "3D/3d.hpp"

int mouseWheel = 0;

bool keyLeft()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) return true; return false;
}

bool keyRight()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return true; return false;
}

bool keyUp()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) return true; return false;
}

bool keyDown()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) return true; return false;
}

bool click()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) return true; return false;
}

bool clickLeft()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) return true; return false;
}

bool keyInventory()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) return true; return false;
}

bool keyEscape()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return true; return false;
}

#endif