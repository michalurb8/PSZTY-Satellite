#include <vector>
#include <cmath>
#include <iostream>

#include "Rocket.h"

int Rocket::maxdist;

Rocket::Rocket(int xPos, int yPos, int xVel, int yVel)
{
    maxdist = 3;
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

void Rocket::UpdateRocket(const std::vector<Planet>& planets)
{
    Rocket& r = *this;
    double tempX;
    double tempY;
    r.Move();
    for(auto p : planets)
    {
        tempX = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempX += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempX *= sqrt(tempX);
        tempX = (p.GetXPos() - r.GetXPos())/tempX;
        tempX *= Planet::GetPLANETMASS()/10;

        tempY = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempY += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempY *= sqrt(tempY);
        tempY = (p.GetYPos() - r.GetYPos())/tempY;
        tempY *= Planet::GetPLANETMASS()/10;

        if(abs(p.GetXPos() - r.GetXPos()) + abs(p.GetYPos() - r.GetYPos()) > Rocket::maxdist)
        {
            r.Accel(tempX, tempY);
        }
        else
        {
            r.alive = false;
            r.mindist = 0;
        }
    }
}

void Rocket::CalcScore(const Planet& p)
{
    double distX = (this->GetXPos() - p.GetXPos());
    double distY = (this->GetYPos() - p.GetYPos());
    double dist = sqrt(distX * distX + distY * distY);
    if(mindist < dist) mindist = dist;
}