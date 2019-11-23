#include "FlightControl.h"
#include <iostream>

FlightControl::FlightControl()
{
	for (int i = 2; i < 20; ++i)
	{
		planets.push_back(Planet(0, i * 15));
	}
	planets.push_back(Planet(5.0, 250));
	LoadAssets();
}

void FlightControl::LoadAssets()
{
	universe.LoadPlanets(&planets);
	universe.LoadRockets(&rockets);
	universe.LoadAssetsToDraw();
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
		universe.testDrawing();
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