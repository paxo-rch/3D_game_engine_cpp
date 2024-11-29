#include "../conf.hpp"
#include "3d.hpp"

#include <math.h>

View::View(double x, double y, double z, double rx, double ry, double rz)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "3D");
}

void View::update_angles()
{
    cx = cos(this->rx);
    cy = cos(this->ry);
    cz = cos(this->rz);
    sx = sin(this->rx);
    sy = sin(this->ry);
    sz = sin(this->rz);
}

P2 View::perspective(P3 p) {
    // Translation relative
    double pX = -(p.x - this->x);
    double pY = -(p.z - this->z);
    double pZ = (p.y - this->y);

    // Rotation Y (optimisation de l'ordre des calculs)
    double tmpX = cy*pX + sy*pZ;
    double tmpZ = -sy*pX + cy*pZ;
    pX = tmpX;
    pZ = tmpZ;

    // Rotation X 
    double tmpY = cx*pY - sx*pZ;
    tmpZ = sx*pY + cx*pZ;
    pY = tmpY;
    pZ = tmpZ;

    // Vérification de la profondeur
    if (pZ <= 0) return {0, 0};

    // Projection perspective
    double f = 1000 * this->fov / pZ;
    double pX2 = pX * f + WINDOW_WIDTH / 2;
    double pY2 = pY * f + WINDOW_HEIGHT / 2;

    return {pX2, pY2};
}