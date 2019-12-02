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

    int MAXDIST;
    int MAXTIME;
    int TARGET;
    int HOME;

    std::vector<Planet> *planets;
	std::vector<Rocket> *rockets;
    DrawingClass drawingObject;

public:

    void Init(std::vector<Planet>* pArg, std::vector<Rocket>* rArg);

    void SetObjectConstants();	//load constans to Rocket:: and Planet::
    void LoadAssetsToDraw();	//load stuff to drawingObject
    void LoadValues(int homeArg, int targetArg, double distArg, int timeArg);

	void Simulate(bool drawingFlag);			//simulate change of universe in MAXTIME
    void ResetSimulation();

    void DisplayFrame();
	void CloseWindow();
};