#pragma once

#include <vector>
#include <string>

#include "Rocket.h"
#include "Planet.h"
#include "DrawingClass.h"

class Universe
{
    const int ROCKETSIZE = 5;
    const int PLANETRADIUS = 10;
    const int PLANETMASS = 10;
    const int CLOSESTORBIT = 50;
    const int SUNMASS = 50;
    const int G = 10;
    const int MAXDIST = 3; //to be read from file
    const int TARGET = 3;

    std::vector<Planet> *planets;
	std::vector<Rocket> *rockets;
    DrawingClass drawingObject;
public:
    Universe() = delete;
    Universe(std::vector<Planet>* pArg, std::vector<Rocket>* rArg);

    void AddPlanet(unsigned int angleArg, unsigned int radArg);

    void LoadAssetsToDraw();
    void SetUniverseConstants();

	void Simulate();
    void DisplayFrame();
	void CloseWindow();
};