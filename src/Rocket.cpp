#include <vector>
#include <cmath>
#include <iostream>

#include "Rocket.h"

int Rocket::MAXDIST;
int Rocket::PLANETMASS;
int Rocket::G;
int Rocket::TARGET;

Rocket::Rocket(int timeArg, double fiArg, double vArg)
{
    mindist = INT32_MAX;

    alive = false;
    iV = vArg;
    iTime = timeArg;
    iFi = fiArg;
}

void Rocket::Move()
{
    xPos += xVel;
    yPos += yVel;
}

void Rocket::Accel(double xArg, double yArg)
{
    xVel += xArg;
    yVel += yArg;
}

bool Rocket::GetAlive() const
{
    return alive;
}

double Rocket::GetXPos() const
{
    return xPos;
}
double Rocket::GetYPos() const
{
    return yPos;
}
double Rocket::GetXVel() const
{
    return xVel;
}
double Rocket::GetYVel() const
{
    return yVel;
}
int Rocket::GetTime() const
{
    return iTime;
}

double Rocket::GetFi() const
{
	return iFi;
}

double Rocket::GetV() const
{
	return iV;
}

void Rocket::UpdateRocket(std::vector<Planet>* planets, int time)
{
    Rocket& r = *this;
    double deltaX;
    double deltaY;
    double distsq;
    double dist;
    double MGRRR; // - M*G / R^3

	// first move
    r.Move();

	// then calculate stuff for the next move
    for(int i = 0; i < (int)planets->size(); ++i)
    {
        Planet& p = (*planets)[i];
		
		//calculate "wklad do przyspieszenia od planety p"
        deltaX = (r.GetXPos() - p.GetXPos());
        deltaY = (r.GetYPos() - p.GetYPos());
        distsq = (deltaX * deltaX) + (deltaY * deltaY);
        dist = sqrt(distsq);
        MGRRR = -1 * G * PLANETMASS / (distsq * dist);

        if(dist > MAXDIST)
        {
			//add "wklad do przyspieszenia od planety p" to acceleration
            r.Accel(MGRRR * deltaX, MGRRR * deltaY);
			
			//update score
            if(i == TARGET && dist < r.mindist)		
            {
                r.mindist = dist;
            }
        }
		else //crush
        {
            if(i == TARGET)
            {
                mindist = 0;
            }
            r.alive = false;
        }
    }
}
void Rocket::MoveToPlanet(const Planet& p, int time)	//resolve first move after launch
{
    alive = true;

    xPos = p.GetXPos() + MAXDIST * cos(iFi); 
    yPos = p.GetYPos() + MAXDIST * sin(iFi);

    xVel = iV * cos(iFi) + p.GetXVel(time);
    yVel = iV * sin(iFi) + p.GetYVel(time);

    mindist = INT32_MAX;

}

void Rocket::SetPLANETMASS(int Arg)
{
    PLANETMASS = Arg;
}

void Rocket::SetGCONST(int Arg)
{
    G = Arg;
}

void Rocket::SetMAXDIST(int Arg)
{
    MAXDIST = Arg;
}

void Rocket::SetTARGET(int Arg)
{
    TARGET = Arg;
}

void Rocket::SetAlive(bool Arg)
{
    alive = Arg;
}

bool Rocket::operator<(const Rocket& other)
{
	return this->mindist < other.mindist;
}