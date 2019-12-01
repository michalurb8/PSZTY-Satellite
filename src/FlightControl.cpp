#include "FlightControl.h"
#include <iostream>

FlightControl::FlightControl()
:universe(Universe(&planets, &rockets))
{
	for(int i = 0; i < 5; ++i)
		planets.push_back(Planet(i*2, i*100 + 100));
	for(int i = 0; i < 50; ++i)
		rockets.push_back(Rocket(i, -2*i, 0, 0));
	universe.LoadAssetsToDraw();
}

void FlightControl::AddPlanet(unsigned int angleArg, unsigned int radArg)
{
	universe.AddPlanet(angleArg, radArg);
}

void FlightControl::ShellResolve(char choice)
{
	switch (choice)
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
		universe.CloseWindow();
		break;
	case 'd':
		universe.Simulate();
		break;
	default:
		std::cout << "Unknown command. Try 'h' for help." << std::endl;
	}
}

void FlightControl::ShellLoop()
{
	char choice;
	ShellResolve('h');
	do
	{
		std::string temp;
		std::cout << std::endl << "> ";
		std::cin >> temp;
		choice = temp[0];
		ShellResolve(choice);
	} while (choice != 'q');
}