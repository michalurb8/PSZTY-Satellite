#pragma once

#include <vector>
#include <allegro5/allegro.h>
#include "Planet.h"
#include "Rocket.h"

class DrawingClass
{
    ALLEGRO_DISPLAY* disp;
    std::vector<Planet> *planets;
	std::vector<Rocket> *rockets;
	int displaySizeX;
	int displaySizeY;
public:
    DrawingClass();
    ~DrawingClass();
    void Draw();
	void DrawPlanets();
	void DrawRockets();
    void CloseWindow();
    void LoadPlanets(std::vector<Planet>* Arg);
	void LoadRockets(std::vector<Rocket>* Arg);
};