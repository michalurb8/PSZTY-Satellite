#include <fstream>
#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>

#include "Universe.h"
#include "Planet.h"

Universe::Universe(std::vector<Planet>* parg, std::vector<Rocket>* rarg)
{
    planets = parg;
    rockets = rarg;
    SetUniverseConstants();
    LoadAssetsToDraw();
}

void Universe::AddPlanet(unsigned int angleArg, unsigned int radArg)
{
    planets->push_back(Planet(angleArg, radArg));
}

void Universe::Simulate()
{
	for (int i = 0; i < 50000; ++i)
	{
        for(Rocket& r : *rockets)
        {
            if(r.GetAlive())
                r.UpdateRocket(planets);
        }
		for (Planet& a : *planets)
		{
			a.UpdatePos(i);
		}
        DisplayFrame();
        //al_rest(0.01);
	}
}

void Universe::DisplayFrame()
{
    drawingObject.Draw();
}

void Universe::CloseWindow()
{
	drawingObject.CloseWindow();
}

void Universe::LoadAssetsToDraw()
{
    drawingObject.LoadPlanets(planets, TARGET);
    drawingObject.LoadRockets(rockets);
}

void Universe::SetUniverseConstants()
{
    Rocket::SetGCONST(G);
    Rocket::SetPLANETMASS(PLANETMASS);
    Rocket::SetMAXDIST(MAXDIST);

    Planet::SetGCONST(G);
    Planet::SetSUNMASS(SUNMASS);
    Planet::SetCLOSESTORBIT(CLOSESTORBIT);
}