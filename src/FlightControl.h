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

public:
	FlightControl();
	void LoadAssets();

	void ShellResolve(char choice);
	void ShellLoop();
};

