#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <string>

#include "Rocket.h"
#include "Planet.h"
#include "DrawingClass.h"

class Universe
{
    std::vector<Planet> *planets;
	std::vector<Rocket> *rockets;
    DrawingClass drawingObject;
public:
    Universe();

    void AddPlanet(unsigned int angleArg, unsigned int radArg);

    void MoveRocket(Rocket& r);

	void LoadPlanets(std::vector<Planet>* Arg);
	void LoadRockets(std::vector<Rocket>* Arg);
    void LoadAssetsToDraw();

	void Simulate();
    void Display();
	void CloseWindow();
};

#endif