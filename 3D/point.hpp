#include "3d.hpp"
#include "engine.hpp"

class Point : public Object
{
public:
    Point(double x, double y, double z);
    void render(View& view);
};

class Triangle : public Object
{
public:
    Triangle(P3 p1, P3 p2, P3 p3, sf::Color color);
    void render(View& view);

    P3 p1, p2, p3;
    sf::Color color;
};