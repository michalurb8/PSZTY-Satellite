#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "DrawingClass.h"

DrawingClass::DrawingClass()
{
    disp = nullptr;
    al_init();
    al_init_primitives_addon();
	displaySizeX = 1000;
	displaySizeY = 600;
}

void DrawingClass::LoadPlanets(std::vector<Planet> *Arg)
{
    planets = Arg;
}

void DrawingClass::LoadRockets(std::vector<Rocket>* Arg)
{
	rockets = Arg;
}

void DrawingClass::Draw()
{
    if(!disp) disp = al_create_display(displaySizeX, displaySizeY);
    
	al_clear_to_color(al_map_rgb(50,50,99));
	DrawPlanets();
	DrawRockets();
    al_flip_display();
}

void DrawingClass::DrawPlanets()
{
	for (Planet& a : *planets)
	{
		al_draw_filled_circle(a.GetXPos() + displaySizeX / 2, displaySizeY / 2 - a.GetYPos(), Planet::GetPLANETRADIUS(), al_map_rgb(120, 120, 0));
	}
}

void DrawingClass::DrawRockets()
{

}

void DrawingClass::CloseWindow()
{
    al_destroy_display(disp);
    disp = nullptr;
}