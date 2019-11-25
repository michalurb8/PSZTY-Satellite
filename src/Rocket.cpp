#include <vector>
#include <cmath>
#include <iostream>

#include "Rocket.h"

int Rocket::maxdist;

Rocket::Rocket(int xPos, int yPos, int xVel, int yVel)
{
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
int Rocket::GetXPos()
{
    return xPos;
}
int Rocket::GetYPos()
{
    return yPos;
}
double Rocket::GetXVel()
{
    return xVel;
}
double Rocket::GetYVel()
{
    return yVel;
}

void Rocket::UpdateRocket(const std::vector<Planet>& planets)
{
    double tempX;
    double tempY;
    Rocket& r = *this;
    r.Move();
    for(auto p : planets)
    {
        tempX = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempX += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempX *= sqrt(tempX);
        tempX = (p.GetXPos() - r.GetXPos())/tempX;
        tempX *= Planet::GetPLANETMASS();

        tempY = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempY += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempY *= sqrt(tempY);
        tempY = (p.GetYPos() - r.GetYPos())/tempY;
        tempY *= Planet::GetPLANETMASS();

        r.Accel(tempX, tempY);
    }
}