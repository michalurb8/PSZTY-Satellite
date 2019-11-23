#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <string>
#include "Planet.h"

class Universe
{
    std::vector<Planet> planets;
public:
    void ShellResolve(char choice);
    void ShellLoop();
};

#endif