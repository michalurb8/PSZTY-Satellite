#pragma once

#include "Planet.h"

class Rocket
{
    double mindist;
    double xPos, yPos;
    double xVel, yVel;

    bool alive;

    int iTime;
    int iFi;
    double iV;

    static int MAXDIST;
    static int PLANETMASS;
    static int G;
    static int TARGET;

    void Accel(double xArg, double yArg);
    void Move();
    int GetScore(const Planet& p) const;
    
public:
    Rocket() = delete;
    Rocket(int timeArg, double fiArg, double vArg);

    double GetXPos() const;
    double GetYPos() const;
    double GetXVel() const;
    double GetYVel() const;
    int GetTime() const;
    bool GetAlive() const;
    void SetAlive(bool Arg);

    void UpdateRocket(std::vector<Planet>* planets);
    void MoveToPlanet(const Planet& p, int time);

    static void SetPLANETMASS(int Arg);
    static void SetMAXDIST(int Arg);
    static void SetGCONST(int Arg);
    static void SetTARGET(int Arg);
};