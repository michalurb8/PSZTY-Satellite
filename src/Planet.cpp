#include "Planet.h"
#include <cmath>
#include <iostream>

int Planet::SUNMASS;
int Planet::PLANETRADIUS;
int Planet::CLOSESTORBIT;
int Planet::G;

Planet::Planet(double angleArg, unsigned int radArg)
:initialAngle(angleArg),
radius(radArg)
{
	UpdatePos(0); //Move the created planet to its correct position
	CalcVel(); //Set the created planet's velocity
}

void Planet::UpdatePos(unsigned int time) //Move the Planet to its current position
{
    xPos = radius * cos(initialAngle + velocity*time);
    yPos = radius * sin(initialAngle + velocity*time);
}

void Planet::CalcVel() //Calculate planet's velocity, runs once
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

int Planet::GetXVel(int time) const
{
	return -1 * velocity * radius * sin(initialAngle + velocity * time);
}
int Planet::GetYVel(int time) const
{
	return velocity * radius * cos(initialAngle + velocity * time);
}

void Planet::SetSUNMASS(int Arg)
{
	SUNMASS = Arg;
	std::cout << "SUNMASS SET TO " << SUNMASS << std::endl;
}
void Planet::SetCLOSESTORBIT(int Arg)
{
	CLOSESTORBIT = Arg;	
	std::cout << "CLOSEST SET TO " << CLOSESTORBIT << std::endl;
}
void Planet::SetGCONST(int Arg)
{
	G = Arg;
	std::cout << "G SET TO " << G << std::endl;
}