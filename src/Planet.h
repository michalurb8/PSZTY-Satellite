#ifndef PLANET_H
#define PLANET_H

class Planet
{
    static unsigned int mass;

    unsigned int initialAngle;
    unsigned int radius;

    unsigned int xPos, yPos;
    unsigned int velocity;
public:
    Planet(unsigned int angleArg, unsigned int radArg);
    Planet() = delete;

    void UpdatePos(unsigned int time);
    void SetMass(unsigned int massArg);
};

#endif