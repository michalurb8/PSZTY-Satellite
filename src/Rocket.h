#pragma once
#include <vector>
#include "Planet.h"
#include <vector>

class Rocket
{
    double mindist;
    double bonus;			//mindist + bonus == score of the rocket (J value)

    double xPos, yPos;
    double xVel, yVel;

    bool alive;				//crashed => dead

    int iTime;
    double iFi;
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
	int GetFi() const;
	int GetV() const;
    bool GetAlive() const;
    void SetAlive(bool Arg);

    void UpdateRocket(std::vector<Planet>* planets, int time);		//update rockets current position
    void MoveToPlanet(const Planet& p, int time);			//resolving first move of the rocket after launch

    static void SetPLANETMASS(int Arg);
    static void SetGCONST(int Arg);
    static void SetTARGET(int Arg);
    static void SetMAXDIST(int Arg);
	
	bool operator<(const Rocket& other);
};