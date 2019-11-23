#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <string>

#include "Rocket.h"
#include "Planet.h"
#include "DrawingClass.h"

class Universe
{
    std::vector<Planet> planets;
    DrawingClass drawingObject;
public:
    Universe();

    void ShellResolve(char choice);
    void ShellLoop();
    void AddPlanet(unsigned int angleArg, unsigned int radArg);

    void MoveRocket(Rocket& r);

    void LoadAssetsToDraw();
    void Display();
};

#endif