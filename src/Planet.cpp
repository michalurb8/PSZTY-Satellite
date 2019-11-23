#include "Planet.h"
#include <cmath>

unsigned int Planet::mass;

Planet::Planet(unsigned int angleArg, unsigned int radArg)
:initialAngle(angleArg),
radius(radArg),
xPos(0), yPos(0),
velocity(mass/sqrt(radius))
{}

void Planet::UpdatePos(unsigned int time)
{
    xPos = radius * sin(initialAngle + velocity*time);
    yPos = radius * cos(initialAngle + velocity*time);
}

void Planet::SetMass(unsigned int massArg)
{
    mass = massArg;
}