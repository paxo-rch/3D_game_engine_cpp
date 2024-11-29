#include "point.hpp"
#include <iostream>

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->rx = 0;
    this->ry = 0;
    this->rz = 0;
}

void Point::render(View& view)
{
    sf::CircleShape shape(3.f);
    shape.setFillColor(sf::Color::Red);
    P2 p = view.perspective({x, y, z});
    shape.setPosition(p.x, p.y);
    view.window.draw(shape);
}


Triangle::Triangle(P3 p1, P3 p2, P3 p3, sf::Color color)
{
    this->x = (p1.x + p2.x + p3.x) / 3;
    this->y = (p1.y + p2.y + p3.y) / 3;
    this->z = (p1.z + p2.z + p3.z) / 3;

    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    this->color = color;
}

void Triangle::render(View& view)
{
    sf::ConvexShape shape;
    shape.setPointCount(3);
    shape.setPoint(0, sf::Vector2f(view.perspective(p1).x, view.perspective(p1).y));
    shape.setPoint(1, sf::Vector2f(view.perspective(p2).x, view.perspective(p2).y));
    shape.setPoint(2, sf::Vector2f(view.perspective(p3).x, view.perspective(p3).y));
    shape.setFillColor(color);
    view.window.draw(shape);
}