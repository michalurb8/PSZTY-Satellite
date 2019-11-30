#pragma once

#include "Planet.h"

class Rocket
{
    int mindist;
    double xPos, yPos;
    double xVel, yVel;

    bool alive;

    int iTime;
    int iFi;
    int iV;

    static int MAXDIST;
    static int PLANETMASS;
    
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

    static void SetPLANETMASS(int Arg);
    static void SetMAXDIST(int Arg);
};