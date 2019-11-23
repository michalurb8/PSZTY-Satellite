#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <string>

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

    void LoadAssetsToDraw();
    void Display();
};

#endif