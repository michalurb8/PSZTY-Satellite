#include <fstream>
#include <iostream>

#include "Universe.h"

Universe::Universe()
{
    //...constructor
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