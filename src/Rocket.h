#ifndef ROCKET_H
#define ROCKET_H

#include "Planet.h"

class Rocket
{
    static int maxdist;
    int mindist;
    double xPos, yPos;
    double xVel, yVel;

    bool alive;

    int iTime;
    int iFi;
    int iV;
    
public:
    Rocket(int xPos, int yPos, int xVel, int yVel);
    void Move();
    void Accel(double xArg, double yArg);
    double GetXPos() const;
    double GetYPos() const;
    double GetXVel() const;
    double GetYVel() const;
    bool GetAlive() const;
    void CalcScore(const Planet& p);
    void UpdateRocket(const std::vector<Planet>& planets);
};

#endif