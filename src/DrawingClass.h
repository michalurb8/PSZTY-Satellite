#ifndef DRAWUNIVERSE_H
#define DRAWUNIVERSE_H

#include <vector>
#include <allegro5/allegro.h>
#include "Planet.h"

class DrawingClass
{
    ALLEGRO_DISPLAY* disp;
    std::vector<Planet> *planets;
public:
    DrawingClass();
    void Init();
    void Draw();
    void CloseWindow();
    void LoadPlanets(std::vector<Planet> *Arg);
};

#endif