#pragma once

class Planet
{
    double initialAngle;
    int radius;

    int xPos, yPos;
    double velocity;

	static int SUNMASS;
	static int PLANETRADIUS;
	static int CLOSESTORBIT;
	static int G;

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