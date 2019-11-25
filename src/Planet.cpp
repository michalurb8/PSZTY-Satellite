#include "Planet.h"
#include <cmath>
#include <iostream>


Planet::Planet(double angleArg, unsigned int radArg)
	:initialAngle(angleArg),
	radius(radArg)
{
	if(radius > 49)
		velocity = (MASS / (sqrt(radius) * radius))/50.0;
	else velocity = (MASS / (343.0))/50.0;

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

int Planet::GetPLANETMASS()
{
	return MASS;
}