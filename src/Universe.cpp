#include <fstream>
#include <iostream>
#include <cmath>

#include "Universe.h"

Universe::Universe()
{
	for (int i = 0; i < 20; ++i)
	{
		planets.push_back(Planet(i, 25* i));
	}
	planets.push_back(Planet(0.5, 250));
    LoadAssetsToDraw();
}
void Universe::AddPlanet(unsigned int angleArg, unsigned int radArg)
{
    planets.push_back(Planet(angleArg, radArg));
}

void Universe::Display()
{
    drawingObject.Draw();
}

void Universe::LoadAssetsToDraw()
{
    drawingObject.LoadPlanets(&planets);
    //..rockets
}

void Universe::MoveRocket(Rocket& r)
{
    int tempX;
    int tempY;
    for(auto p : planets)
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

void Universe::ShellResolve(char choice)
{
    switch(choice)
    {
	case 'q':
		std::cout << "Shutting down..." << std::endl << std::endl;
		return;
        case 'h':
            std::cout << std::endl <<
            "Available commands:" << std::endl << std::endl <<
            "   h - Display this help message" << std::endl <<
            "   d - Display generation" << std::endl <<
            "   c - Close window" << std::endl <<
            "   q - Exit" << std::endl;
			return;
        case 'c':
            drawingObject.CloseWindow();
            break;
        case 'd':
            Display();
            break;
        default:
            std::cout << "Unknown command. Try 'h' for help." << std::endl;
    }
}

void Universe::ShellLoop()
{
    char choice;
    ShellResolve('h');
    do
    {
        std::string temp;
        std::cout << std::endl << "> ";
        std::cin >> temp;
        choice =  temp[0];
        ShellResolve(choice);
    } while(choice != 'q');
}