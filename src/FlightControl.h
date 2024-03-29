#pragma once
#include "Universe.h"
#include "Planet.h"
#include "Rocket.h"
#include "Generation.h"
#include <vector>

class FlightControl
{
	bool dataCorrect;

	Universe universe;
	Generation generation;

	std::vector<Planet> planets;
	std::vector<Rocket> rockets;

	void LoadAssets();
    void AddPlanet(unsigned int angleArg, unsigned int radArg);
	void LoadDataFromFile();
	void Generate();
public:
	FlightControl();
 	void PassGeneration();

	void ShellResolve(char choice);
	void ShellLoop();				//infinite loop receiving consol commands
};