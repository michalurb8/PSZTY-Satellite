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

    int MAXDIST = 3; //to be read from file
    int MAXTIME = 50000; //to be read
    int TARGET = 2; //to be read
    int HOME = 1; //to be read

    std::vector<Planet> *planets;
	std::vector<Rocket> *rockets;
    DrawingClass drawingObject;

public:
    Universe() = delete;
    Universe(std::vector<Planet>* pArg, std::vector<Rocket>* rArg);

    void SetObjectConstants();	//load constans to Rocket:: and Planet::
    void LoadAssetsToDraw();	//load stuff to drawingObject
    void LoadFromFile(int homeArg, int targetArg, double distArg, int timeArg);

	void Simulate();			//simulate change of universe in MAXTIME
    void ResetSimulation();

    void DisplayFrame();
	void CloseWindow();
};