#ifndef ROCKET_H
#define ROCKET_H

#include "Planet.h"

class Rocket
{
    static int maxdist;
    int mindist;
    int xPos, yPos;
    double xVel, yVel;

    int iTime;
    int iFi;
    int iV;
    
public:
    Rocket(int xPos, int yPos, int xVel, int yVel);
    void Move();
    void Accel(double xArg, double yArg);
    int GetXPos();
    int GetYPos();
    double GetXVel();
    double GetYVel();
    void UpdateRocket(const std::vector<Planet>& planets);
};

#endif