#include <fstream>
#include <iostream>
#include <cmath>
#include <allegro5/allegro.h>

#include "Universe.h"
#include "Planet.h"

Universe::Universe(std::vector<Planet>* pArg, std::vector<Rocket>* rArg)
{
    planets = pArg;
    rockets = rArg;
    SetObjectConstants();
    LoadAssetsToDraw();
}

void Universe::Simulate()
{
    ResetSimulation();
	for(int time = 0; time < MAXTIME; ++time)
	{
        for(Rocket& r : *rockets)
        {
            if(time == r.GetTime())
                r.MoveToPlanet((*planets)[HOME], time);
            if(r.GetAlive())
                r.UpdateRocket(planets);
        }
		for(Planet& p : *planets)
		{
			p.UpdatePos(time);
		}
        DisplayFrame();
        al_rest(0.01);
	}
}

void Universe::ResetSimulation()
{
    for(Planet& p : *planets)
    {
        p.UpdatePos(0);
    }
    for(Rocket& r : *rockets)
    {
        r.SetAlive(false);
    }
}

void Universe::LoadAssetsToDraw()
{
    drawingObject.LoadPlanets(planets, HOME, TARGET);
    drawingObject.LoadRockets(rockets);
}

void Universe::DisplayFrame()
{
    drawingObject.DisplayFrame();
}

void Universe::CloseWindow()
{
	drawingObject.CloseWindow();
}

void Universe::SetObjectConstants()
{
    Rocket::SetGCONST(G);
    Rocket::SetPLANETMASS(PLANETMASS);
    Rocket::SetMAXDIST(MAXDIST);
    Rocket::SetTARGET(TARGET);

    Planet::SetGCONST(G);
    Planet::SetSUNMASS(SUNMASS);
    Planet::SetCLOSESTORBIT(CLOSESTORBIT);
}