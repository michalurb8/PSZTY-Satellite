#pragma once
#include "Rocket.h"
#include "Planet.h"
#include <vector>

class Generation
{
	std::vector<Rocket>* rockets;
	static int mi;
	static int lambda;

public:
	
	Generation(int miArg, int lambdaArg);
	void Reproduce();		//reproduce and add descendants to rockets
	void SelectParents(std::vector<Rocket>* selectedRockets);
	void Crossbreeding(std::vector<Rocket>* parents, std::vector<Rocket>* babies);
	void Kill();					//select some rockets and remove others from rockets
};