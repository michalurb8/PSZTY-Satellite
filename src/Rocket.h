#ifndef ROCKET_H
#define ROCKET_H

class Rocket
{
    static int maxdist;
    int mindist;
    int xPos, yPos;
    double xVel, yVel;

    int iTime;
    int iFi;
    int iV;
    
public:
    Rocket();
    void Move();
    void Accel(int xVel, int yVel);
    int GetXPos();
    int GetYPos();
    int GetXVel();
    int GetYVel();
};

#endif