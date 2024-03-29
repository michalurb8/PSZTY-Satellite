#include "Planet.h"
#include <cmath>

int Planet::SUNMASS;
int Planet::PLANETRADIUS;
int Planet::CLOSESTORBIT;
int Planet::G;

Planet::Planet(double angleArg, unsigned int radArg)
:initialAngle(angleArg),
radius(radArg)
{
	UpdatePos(0); //Move the created planet to its correct position
	SetInitialVel(); //Set the created planet's velocity
}

void Planet::UpdatePos(unsigned int time) //Move the Planet to its current position
{
    xPos = radius * cos(initialAngle + velocity*time);
    yPos = radius * sin(initialAngle + velocity*time);
}

void Planet::SetInitialVel()//Calculate planet's velocity, runs once
{
	// formula for the angular velocity from: gravity = centripetal force
	// if the planet is too close to the center of the universe, its velocity is capped
	if(radius > CLOSESTORBIT)
		velocity = sqrt((double)SUNMASS * G/(radius * radius * radius));
	else
		velocity = sqrt((double)SUNMASS * G/(CLOSESTORBIT * CLOSESTORBIT * CLOSESTORBIT));
}
int Planet::GetXPos() const
{
	return xPos;
}

int Planet::GetYPos() const
{
	return yPos;
}

double Planet::GetXVel(int time) const
{
	return -1 * velocity * radius * sin(initialAngle + time * velocity);
}
double Planet::GetYVel(int time) const
{
	return velocity * radius * cos(initialAngle + time * velocity);
}

void Planet::SetSUNMASS(int Arg)
{
	SUNMASS = Arg;
}
void Planet::SetCLOSESTORBIT(int Arg)
{
	CLOSESTORBIT = Arg;	
}
void Planet::SetGCONST(int Arg)
{
	G = Arg;
}