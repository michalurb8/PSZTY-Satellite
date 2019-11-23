#include "Planet.h"
#include <cmath>

void Planet::UpdatePos(unsigned int time)
{
    xPos = radius * sin(initialAngle + velocity*time);
    yPos = radius * cos(initialAngle + velocity*time);
}

Planet::Planet(unsigned int angleArg, unsigned int radArg)
:initialAngle(angleArg), radius(radArg)
{
    
}
