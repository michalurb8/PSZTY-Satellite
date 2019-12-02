#pragma once
#include "Rocket.h"
#include "Planet.h"
#include <vector>

class Generation
{
	std::vector<Rocket>* rockets;
	const int lambda = 100;
	int MAXTIME;

	void SelectParents(std::vector<Rocket>* selectedRockets);
	void Crossbreeding(std::vector<Rocket>* parents, std::vector<Rocket>* babies);
public:
	Rocket GetBest();
	void LoadValues(int maxtime);
	void Init(std::vector<Rocket>* rArg);
	void Reproduce();		//reproduce and add descendants to rockets
	void Kill();					//select some rockets and remove others from rockets
};