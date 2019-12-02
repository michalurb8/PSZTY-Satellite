#pragma once

class Planet
{
	//variables defining planets starting position
    double initialAngle;
    int radius;			

	//variables defining planets current position and velocity
    int xPos, yPos;
    double velocity;

	//constants
	static int SUNMASS;				//used to calculate planets velocity
	static int PLANETRADIUS;		//used for drawing
	static int CLOSESTORBIT;		//used to cap planet velocity
	static int G;					//gravity constant

public:
    Planet(double angleArg, unsigned int radArg);
    Planet() = delete;

    void UpdatePos(unsigned int time);
	void SetInitialVel();

	int GetXPos() const;
	int GetYPos() const;
	double GetXVel(int time) const;
	double GetYVel(int time) const;

	static void SetSUNMASS(int Arg);
	static void SetCLOSESTORBIT(int Arg);
	static void SetGCONST(int Arg);
};