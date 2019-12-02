#pragma once
#include "Rocket.h"
#include "Planet.h"
#include <vector>

class Generation
{
	std::vector<Rocket>* rockets;

public:
	Generation();
	void LetsHaveSomeBabies();		//reproduce and add descendants to rockets
	void Kill();					//select some rockets and remove others from rockets
};