#ifndef PLANET_H
#define PLANET_H


class Planet
{
    double initialAngle;
    int radius;

    int xPos, yPos;
    double velocity;

	static const int MASS = 30000;
	static const int PLANETRADIUS = 10;

public:
    Planet(double angleArg, unsigned int radArg);
    Planet() = delete;

    void UpdatePos(unsigned int time);

	int GetXPos();
	int GetYPos();
	static int GetPLANETRADIUS();
	static int GetPLANETMASS();
};

#endif