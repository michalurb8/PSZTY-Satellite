#include"Generation.h"
#include <vector>
#include <time.h>
#include <algorithm>

int Generation::mi;
int Generation::lambda;

Generation::Generation(int miArg, int lambdaArg)
{
	mi = miArg;
	lambda = lambdaArg;
}

void Generation::Reproduce()
{
	std::vector<Rocket> parents;
	std::vector<Rocket> babies;

	SelectParents(&parents);

	Crossbreeding(&parents, &babies);

	//add babies
	for (Rocket r : babies)
	{
		rockets->push_back(r);
	}
}

void Generation::SelectParents(std::vector<Rocket>* selectedRockets)
{
	srand(time(NULL));

	for (int i = 0; i < lambda; ++i)
	{
		selectedRockets->push_back((*rockets)[rand() % (rockets->size())]);
	}
}

void Generation::Crossbreeding(std::vector<Rocket>* parents, std::vector<Rocket>* babies)
{
	int tempTime, tempFi, tempV;
	for (std::vector<Rocket>::iterator i = parents->begin(); i != parents->end(); ++i)
	{
		std::vector<Rocket>::iterator j = i + 1;
		if (j == parents->end())
			j = parents->begin();

		tempTime = (i->GetTime() + j->GetTime()) / 2;
		tempFi = (i->GetFi() + j->GetFi()) / 2;
		tempV = (i->GetV() + j->GetV()) / 2;

		babies->push_back(Rocket(tempTime, tempFi, tempV));
	}
}

void Generation::Kill()
{
	std::sort(rockets->begin(), rockets->end());
	int rocketsSize = rockets->size();
	for (int i = lambda; i < rocketsSize; ++i)
	{
		rockets->pop_back();
	}
}
