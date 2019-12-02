#include"Generation.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

void Generation::Init(std::vector<Rocket>* rArg)
{
	rockets = rArg;
	for(auto a : *rockets) std::cout << a.GetAlive() << std::endl;
	rockets->clear();
	srand(time(NULL));

	for(int i = 0; i < 300; ++i)
	{
		Rocket temp = Rocket(rand()%500, (double)(rand()%22), rand()%8);///import maxtime TODO
		rockets->push_back(temp);
	}
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
	while(rockets->size() > lambda)
	{
		rockets->pop_back();
	}
}
