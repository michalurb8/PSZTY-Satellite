#ifndef PLANET_H
#define PLANET_H

class Planet
{
    static unsigned int mass;
    unsigned int xPos, yPos;
    unsigned int velocity;
    unsigned int initialAngle;
    unsigned int radius;
    unsigned int R,G,B;
public:
    void UpdatePos(unsigned int time);
    Planet(unsigned int angleArg, unsigned int radArg);
};

#endif