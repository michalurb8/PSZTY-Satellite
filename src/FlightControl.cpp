#include "FlightControl.h"
#include <iostream>
#include <fstream>
#include <ctime>

FlightControl::FlightControl()
{
	srand(time(NULL));

	dataCorrect = false;

	std::cout << "OK" << std::endl;
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
			"   P - Pass 10 generations" << std::endl <<
			"   g - Generate random data" << std::endl <<
			"   q - Exit" << std::endl;
		return;
	case 'c':
		universe.CloseWindow();
		break;
	case 'l':
		LoadDataFromFile();
		break;
	case 'g':
		Generate();
		break;
	case 'p':
		if(dataCorrect)
			PassGeneration();
		else
			std::cout << "Please load data" << std::endl;
		break;
	case 'P':
		if(dataCorrect)
			for(int i = 0; i < 10; ++i) PassGeneration();
		else
			std::cout << "Please load data" << std::endl;
		break;
	case 'd':
		if(dataCorrect)
			universe.Simulate(1);
		else
			std::cout << "Please load data" << std::endl;
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
    universe.SetObjectConstants();
	planets.clear();
	std::ifstream input("input.txt");
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

	universe.LoadValues(home, target, maxdist, maxtime);
	generation.LoadValues(maxtime);

	universe.Init(&planets, &rockets);
	generation.Init(&rockets);


	dataCorrect = true;

	std::cout << "Data loaded successfully" << std::endl;
}

void FlightControl::PassGeneration()
{
	generation.Reproduce();
	universe.Simulate(0);
	generation.Kill();
}

void FlightControl::Generate()
{
	std::ofstream output("input.txt");
	int n = rand()%10 + 10;
	output << n << std::endl;
	for(int i = 0; i < n; ++i)
	{
		output << rand()%22 << " " << rand()%500 << std::endl;
	}
	output << 0 << std::endl;
	output << 1 << std::endl;
	output << 5 << std::endl;
	output << 1500 << std::endl;
	output.close();
}