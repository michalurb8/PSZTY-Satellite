#ifndef PLANET_H
#define PLANET_H


class Planet
{
    double initialAngle;
    int radius;

    int xPos, yPos;
    int velocity;

	static const int mass = 300;
	static const int PLANETRADIUS = 10;

public:
    Planet(double angleArg, unsigned int radArg);
    Planet() = delete;

    void UpdatePos(unsigned int time);

	int getXPos();
	int getYPos();
	static int getPLANETRADIUS();
};

#endif//*************8