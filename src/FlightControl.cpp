#include "FlightControl.h"
#include <iostream>

FlightControl::FlightControl()
:universe(Universe(&planets, &rockets))
{
	for(int i = 0; i < 5; ++i)
		planets.push_back(Planet(i, i*50 + 100));
	for(int i = 0; i < 5; ++i)
		rockets.push_back(Rocket(10*i, -20*i, 1, 2));
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