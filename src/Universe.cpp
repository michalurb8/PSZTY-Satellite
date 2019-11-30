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
    SetUniverseConstants();
    LoadAssetsToDraw();
}

void Universe::AddPlanet(unsigned int angleArg, unsigned int radArg)
{
    Planet temp = Planet(angleArg, radArg);
    temp.CalcVel();
    planets->push_back(temp);
}

void Universe::Simulate()
{
	for (int i = 0; i < 50000; ++i)
	{
        for(Rocket& r : *rockets)
        {
            if(r.GetAlive())
                r.UpdateRocket(*planets);
        }
		for (Planet& a : *planets)
		{
			a.UpdatePos(i);
		}
        Display();
        al_rest(0.01);
	}
}

void Universe::Display()
{
    drawingObject.Draw();
}

void Universe::CloseWindow()
{
	drawingObject.CloseWindow();
}

void Universe::LoadAssetsToDraw()
{
    drawingObject.LoadPlanets(planets);
    drawingObject.LoadRockets(rockets);
}

void Universe::SetUniverseConstants()
{
    Rocket::SetPLANETMASS(PLANETMASS);
    Rocket::SetMAXDIST(MAXDIST);

    Planet::SetGCONST(G);
    Planet::SetSUNMASS(SUNMASS);
    Planet::SetCLOSESTORBIT(CLOSESTORBIT);
}

void Universe::MoveRocket(Rocket& r)
{
    int tempX;
    int tempY;
    for(auto p : *planets)
    {
        r.Move();
        tempX = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempX += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempX *= sqrt(tempX);
        tempX = (p.GetXPos() - r.GetXPos())/tempX;

        tempY = (r.GetXPos() - p.GetXPos()) * (r.GetXPos() - p.GetXPos());
        tempY += (r.GetYPos() - p.GetYPos()) * (r.GetYPos() - p.GetYPos());
        tempY *= sqrt(tempY);
        tempY = (p.GetXPos() - r.GetXPos())/tempY;
        r.Accel(tempX, tempY);
    }
}