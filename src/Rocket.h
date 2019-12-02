#pragma once

#include "Planet.h"

class Rocket
{
    double mindist;			//score of the rocket (J function)
    double xPos, yPos;
    double xVel, yVel;

    bool alive;				//crashed => dead

    int iTime;
    int iFi;
    double iV;

    static int MAXDIST;		//at that distance (between rocket and planet) rocket crushes
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

    void UpdateRocket(std::vector<Planet>* planets);		//update rockets current position
    void MoveToPlanet(const Planet& p, int time);			//resolving first move of the rocket after launch

    static void SetPLANETMASS(int Arg);
    static void SetMAXDIST(int Arg);
    static void SetGCONST(int Arg);
    static void SetTARGET(int Arg);
};