#include "Rocket.h"

int Rocket::maxdist;

void Rocket::Move()
{
    xPos += (int)xVel;
    yPos += (int)yVel;
}
void Rocket::Accel(int xArg, int yArg)
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
int Rocket::GetXVel()
{
    return xVel;
}
int Rocket::GetYVel()
{
    return yVel;
}

void Rocket::CalcMovement(Rocket& r)
{
    int tempX;
    int tempY;
    for(auto p : planets)
    {
        r.Move();
        tempX = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempX += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempX *= sqrt(tempX);
        tempX = (p.GetXPos() - r.GetXPos())/tempX;

        tempY = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempY += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempY *= sqrt(tempY);
        tempY = (p.GetXPos() - r.GetXPos())/tempY;
        r.Accel(tempX, tempY);
    }
}