#include"Generation.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

void Generation::Init(std::vector<Rocket>* rArg)
{
	rockets = rArg;
	rockets->clear();
	srand(time(NULL));

	for(int i = 0; i < 300; ++i)
	{
		Rocket temp = Rocket(rand()%MAXTIME, (double)(rand()%22), rand()%3 + 3);///import maxtime TODO
		rockets->push_back(temp);
	}
}

void Generation::LoadValues(int maxtime)
{
	MAXTIME = maxtime;	
}

void Generation::Reproduce()//produce lambda babies
{
	std::vector<Rocket> parents;
	std::vector<Rocket> babies;

	SelectParents(&parents);

	Crossbreeding(&parents, &babies);

	for (Rocket r : babies)
	{
		rockets->push_back(r);
	}
}

void Generation::SelectParents(std::vector<Rocket>* selectedRockets)//select random parents for breeding
{
	for (int i = 0; i < lambda; ++i)
	{
		selectedRockets->push_back((*rockets)[rand() % (rockets->size())]);
	}
}

void Generation::Crossbreeding(std::vector<Rocket>* parents, std::vector<Rocket>* babies)
{//breed every consecutive pair of rockets, create lambda baby rockets
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

void Generation::Kill() //kill all but lambda of the best rockest
{
	std::sort(rockets->begin(), rockets->end());
	while((int)rockets->size() > lambda)
	{
		rockets->pop_back();
	}
}

Rocket Generation::GetBest() //return the rocket with the best score
{
	std::sort(rockets->begin(), rockets->end());
	return (*rockets)[0];
}