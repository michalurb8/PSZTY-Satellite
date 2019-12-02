#pragma once
#include "Universe.h"
#include "Planet.h"
#include "Rocket.h"
#include <vector>

class FlightControl
{
	Universe universe;

	std::vector<Planet> planets;
	std::vector<Rocket> rockets;

	void LoadAssets();
    void AddPlanet(unsigned int angleArg, unsigned int radArg);
	void LoadDataFromFile();
public:
	FlightControl();

	void ShellResolve(char choice);
	void ShellLoop();				//infinite loop receiving consol commands
};