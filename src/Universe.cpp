#include <fstream>
#include <cmath>

#include "Universe.h"

void Universe::Init(std::vector<Planet>* pArg, std::vector<Rocket>* rArg)
{
    planets = pArg;
    rockets = rArg;
    LoadAssetsToDraw();
}

void Universe::Simulate(bool drawingFlag)
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
			//launch rocket if necessary
            if(time == r.GetTime())
                r.MoveToPlanet((*planets)[HOME], time);
			
            if(r.GetAlive())
                r.UpdateRocket(planets, time);
        }
        if(drawingFlag)
        {
            DisplayFrame();
            al_rest(0.01);
        }
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

void Universe::LoadValues(int homeArg, int targetArg, double distArg, int timeArg)
{
    HOME = homeArg;
    TARGET = targetArg;
    MAXDIST = distArg;
    MAXTIME = timeArg;
    Rocket::SetTARGET(targetArg);
    Rocket::SetMAXDIST(distArg);
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

    Planet::SetGCONST(G);
    Planet::SetSUNMASS(SUNMASS);
    Planet::SetCLOSESTORBIT(CLOSESTORBIT);
}