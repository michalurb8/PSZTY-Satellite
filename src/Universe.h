#pragma once

#include <vector>
#include <string>

#include "Rocket.h"
#include "Planet.h"
#include "DrawingClass.h"

class Universe
{
    const int PLANETMASS = 20;
    const int SUNMASS = 50;
    const int G = 5;
    const int CLOSESTORBIT = 50;

    const int MAXDIST = 3; //to be read from file
    const int MAXTIME = 50000; //to be read
    const int TARGET = 2; //to be read
    const int HOME = 1; //to be read

    std::vector<Planet> *planets;
	std::vector<Rocket> *rockets;
    DrawingClass drawingObject;

public:
    Universe() = delete;
    Universe(std::vector<Planet>* pArg, std::vector<Rocket>* rArg);

    void SetObjectConstants();
    void LoadAssetsToDraw();

	void Simulate();
    void ResetSimulation();

    void DisplayFrame();
	void CloseWindow();
};