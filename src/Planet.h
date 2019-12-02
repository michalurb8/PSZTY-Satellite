#pragma once

class Planet
{
	//variables defining planets starting position
    double initialAngle;
    int radius;			

	//variables defining planets current position
    int xPos, yPos;
    double velocity;

	//constans
	static int SUNMASS;				//mass of the center of the solar system
	static int PLANETRADIUS;		
	static int CLOSESTORBIT;		//closest possible distance planet<->sun
	static int G;					//sta³a grawitacyjna

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