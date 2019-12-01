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
    alive = true;
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

void Rocket::UpdateRocket(std::vector<Planet>* planets)
{
    Rocket& r = *this;
    double deltaX;
    double deltaY;
    double distsq;
    double dist;
    double MGRRR; // - M*G / R^3
    r.Move();
    for(unsigned int i = 0; i < planets->size(); ++i)
    {
        Planet& p = (*planets)[i];

        deltaX = (r.GetXPos() - p.GetXPos());
        deltaY = (r.GetYPos() - p.GetYPos());
        distsq = (deltaX * deltaX) + (deltaY * deltaY);
        dist = sqrt(distsq);

        MGRRR = -1 * G * PLANETMASS / (distsq * dist);

        if(dist > MAXDIST)
        {
            r.Accel(MGRRR * deltaX, MGRRR * deltaY);
            if(i == TARGET && dist < r.mindist) 
            {
                r.mindist = dist;
            }
        }
        else
        {
            std::cout << "rocket ded" << std::endl;
            r.alive = false;
            r.mindist = 0;
        }
    }
}
void Rocket::MoveToPlanet(const Planet& p, int time)
{
    alive = true;

    xPos = p.GetXPos() + MAXDIST * cos(iFi); 
    yPos = p.GetYPos() + MAXDIST * sin(iFi);

    std::cout << p.GetXVel(time) << " " << p.GetYVel(time) <<  std::endl;

    xVel = p.GetXVel(time) + iV * cos(iFi);
    yVel = p.GetYVel(time) + iV * sin(iFi);

    mindist = 10000;

    Move();//move it
}

void Rocket::SetPLANETMASS(int Arg)
{
    PLANETMASS = Arg;
}

void Rocket::SetTARGET(int Arg)
{
    TARGET = Arg;
}

void Rocket::SetMAXDIST(int Arg)
{
    MAXDIST = Arg;
}

void Rocket::SetGCONST(int Arg)
{
    G = Arg;
}
void Rocket::SetAlive(bool Arg)
{
    alive = Arg;
}
