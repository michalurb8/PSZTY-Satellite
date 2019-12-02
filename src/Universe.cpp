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

	//time loop
	for(int time = 0; time < MAXTIME; ++time)
	{
		// move every rocket
		for(Planet& p : *planets)
		{
			p.UpdatePos(time);
		}
        for(Rocket& r : *rockets)
        {
			//launch rocket(s) if necessary
            if(time == r.GetTime())
                r.MoveToPlanet((*planets)[HOME], time);
			
            if(r.GetAlive())
                r.UpdateRocket(planets);
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

void Universe::LoadFromFile(int homeArg, int targetArg, double distArg, int timeArg)
{
    HOME = homeArg;
    TARGET = targetArg;
    MAXDIST = distArg;
    MAXTIME = timeArg;
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