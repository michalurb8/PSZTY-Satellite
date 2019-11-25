#include "Planet.h"
#include <cmath>
#include <iostream>

const double SMALLRADIUS = 50;
const double G = 10;

Planet::Planet(double angleArg, unsigned int radArg)
	:initialAngle(angleArg),
	radius(radArg)
{
	if(radius > SMALLRADIUS)//gravity = centripetal force
		velocity = sqrt(MASS* G/(radius * radius * radius));
	else
		velocity = sqrt(MASS* G/(SMALLRADIUS * SMALLRADIUS * SMALLRADIUS));
	UpdatePos(0);
}

void Planet::UpdatePos(unsigned int time)
{
    xPos = radius * cos(initialAngle + velocity*time);
    yPos = radius * sin(initialAngle + velocity*time);
}

int Planet::GetXPos() const
{
	return xPos;
}

int Planet::GetYPos() const
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