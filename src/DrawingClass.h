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
    int targetPlanetId;
    int homePlanetId;

	const int screenX = 1000;
	const int screenY = 1000;
    const int rocketSize = 5;
    const int planetSize = 10;

	void DrawPlanets();
	void DrawRockets();

public:
    DrawingClass();
    ~DrawingClass();

    void LoadPlanets(std::vector<Planet> *Arg, int homeId, int targetId);
	void LoadRockets(std::vector<Rocket>* Arg);

    void DisplayFrame();
    void CloseWindow();
};