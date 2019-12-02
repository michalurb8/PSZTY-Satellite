#include "FlightControl.h"
#include <iostream>
#include <fstream>
#include <ctime>

FlightControl::FlightControl()
{
	srand(time(NULL));
	universe.Init(&planets, &rockets);
	generation.Init(&rockets);
	for(int i = 0; i < 15; ++i)
		planets.push_back(Planet((double)(rand()%220)/10, rand()%500));
}

void FlightControl::AddPlanet(unsigned int angleArg, unsigned int radArg)
{
	planets.push_back(Planet(angleArg, radArg));
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
			"   l - Load data from file input.txt" << std::endl <<
			"   p - Pass generation" << std::endl <<
			"   q - Exit" << std::endl;
		return;
	case 'c':
		universe.CloseWindow();
		break;
	case 'l':
		LoadDataFromFile();
		break;
	case 'p':
		PassGeneration();
		break;
	case 'd':
		universe.Simulate(1);
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

void FlightControl::LoadDataFromFile()
{
	planets.clear();
	std::ifstream input("C:\\Users\\Dell\\source\\repos\\PSZTY-Satellite\\src\\input.txt");
	if(!input.good())
	{
		std::cout << "Error reading file" << std::endl;
		return;
	}
	int n, maxtime, home, target;
	double radius, angle, maxdist;
	input >> n;
	for(int i = 0; i < n; ++i)
	{
		input >> angle >> radius;
		AddPlanet(angle, radius);
	}
	input >> home >> target >> maxdist >> maxtime;
	input.close();
	universe.LoadFromFile(home, target, maxdist, maxtime);
	std::cout << "Data loaded successfully" << std::endl;
}

void FlightControl::PassGeneration()
{
	generation.Reproduce();
	universe.Simulate(0);
	generation.Kill();
}