#include <fstream>
#include <iostream>
#include <cmath>

#include "Universe.h"

Universe::Universe()
{
}
void Universe::AddPlanet(unsigned int angleArg, unsigned int radArg)
{
    planets->push_back(Planet(angleArg, radArg));
}

void Universe::testDrawing()
{
	for (int i = 0; i < 50; ++i)
	{
		for (Planet& a : *planets)
		{
			a.UpdatePos(i);
		}
		drawingObject.Draw();
		Sleep(10);
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
    //..rockets
}

void Universe::ShellResolve(char choice)
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

void Universe::LoadPlanets(std::vector<Planet>* Arg)
{
	planets = Arg;
}

void Universe::LoadRockets(std::vector<Rocket>* Arg)
{
	rockets = Arg;
}

