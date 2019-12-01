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
    static int G;

    void Accel(double xArg, double yArg);
    int GetScore(const Planet& p);
    
public:
    Rocket(int xPos, int yPos, int xVel, int yVel);
    void Move();
    double GetXPos() const;
    double GetYPos() const;
    double GetXVel() const;
    double GetYVel() const;
    bool GetAlive() const;
    void UpdateRocket(std::vector<Planet>* planets);

    static void SetPLANETMASS(int Arg);
    static void SetMAXDIST(int Arg);
    static void SetGCONST(int Arg);
};