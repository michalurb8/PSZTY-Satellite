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