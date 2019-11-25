#include "Planet.h"
#include <cmath>
#include <iostream>


Planet::Planet(double angleArg, unsigned int radArg)
	:initialAngle(angleArg),
	radius(radArg)
{
	velocity = (mass / (sqrt(radius) * radius));
	UpdatePos(0);
}

void Planet::UpdatePos(unsigned int time)
{
    xPos = radius * cos(initialAngle + velocity*time);
    yPos = radius * sin(initialAngle + velocity*time);
}

int Planet::GetXPos()
{
	return xPos;
}

int Planet::GetYPos()
{
	return yPos;
}

int Planet::GetPLANETRADIUS()
{
	return PLANETRADIUS;
}