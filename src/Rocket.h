#pragma once
#include <vector>
#include "Planet.h"
#include <vector>

class Rocket
{
    double mindist;         //mindist == score

    double xPos, yPos;
    double xVel, yVel;
    bool alive;				//crashed planets are not drawn or simulated

    int iTime;
    double iFi;
    double iV;

    static int MAXDIST;		//at that distance (between rocket and planet) rocket crushes
    static int PLANETMASS;
    static int G;
    static int TARGET;

    void Accel(double xArg, double yArg);
    void Move();
    
public:
    Rocket() = delete;
    Rocket(int timeArg, double fiArg, double vArg);

    double GetXPos() const;
    double GetYPos() const;
    double GetXVel() const;
    double GetYVel() const;
    int GetTime() const;
	double GetFi() const;
	double GetV() const;
    bool GetAlive() const;
    void SetAlive(bool Arg);

    void UpdateRocket(std::vector<Planet>* planets, int time);	//update rockets current position and score
    void MoveToPlanet(const Planet& p, int time);			    //Launch the rocket

    static void SetPLANETMASS(int Arg);
    static void SetGCONST(int Arg);
    static void SetTARGET(int Arg);
    static void SetMAXDIST(int Arg);
	
	bool operator<(const Rocket& other);
};