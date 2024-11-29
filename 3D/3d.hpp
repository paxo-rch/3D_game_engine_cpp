#ifndef _3D_HPP_
#define _3D_HPP_

#include <SFML/Graphics.hpp>

struct P3
{
    double x, y, z;
};

struct P2
{
    double x, y;
};

class View
{
    public:
        View(double x, double y, double z, double rx, double ry, double rz);

        void update_angles();
        P2 perspective(P3 p);

        sf::RenderWindow window;

        double x, y, z, rx, ry, rz = 0;
        double cx, cy, cz = 0;
        double sx, sy, sz = 0;
        double fov = 1.0;
};

#endif