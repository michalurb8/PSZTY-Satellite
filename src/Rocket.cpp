#include <vector>
#include <cmath>
#include <iostream>

#include "Rocket.h"

int Rocket::MAXDIST;
int Rocket::PLANETMASS;
int Rocket::G;

Rocket::Rocket(int xPos, int yPos, int xVel, int yVel)
{
    alive = true;
    this->xPos = xPos;
    this->yPos = yPos;
    this->xVel = xVel;
    this->yVel = yVel;
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
        }
        else
        {
            std::cout << "rocket ded" << std::endl;
            r.alive = false;
            r.mindist = 0;
        }
    }
}

int Rocket::GetScore(const Planet& p)
{
    double distX = (this->GetXPos() - p.GetXPos());
    double distY = (this->GetYPos() - p.GetYPos());
    double dist = sqrt(distX * distX + distY * distY);
    return dist;
}

void Rocket::SetPLANETMASS(int Arg)
{
    PLANETMASS = Arg;
}

void Rocket::SetMAXDIST(int Arg)
{
    MAXDIST = Arg;
}

void Rocket::SetGCONST(int Arg)
{
    G = Arg;
}