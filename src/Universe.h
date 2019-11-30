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
    const int PLANETMASS = 100;
    const int CLOSESTORBIT = 50;
    const int SUNMASS = 100;
    const int G = 5;
    const int MAXDIST = 3; //to be read from file

    std::vector<Planet> *planets;
	std::vector<Rocket> *rockets;
    DrawingClass drawingObject;
public:
    Universe() = delete;
    Universe(std::vector<Planet>* pArg, std::vector<Rocket>* rArg);

    void AddPlanet(unsigned int angleArg, unsigned int radArg);

    void MoveRocket(Rocket& r);

    void LoadAssetsToDraw();
    void SetUniverseConstants();

	void Simulate();
    void Display();
	void CloseWindow();
};