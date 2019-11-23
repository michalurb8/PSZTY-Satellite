#include "Universe.h"
#include <fstream>
#include <iostream>

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
            "   q - Exit" << std::endl;
			return;
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