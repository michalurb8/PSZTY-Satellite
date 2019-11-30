#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_image.h>

#include "DrawingClass.h"

DrawingClass::DrawingClass()
{
    disp = nullptr;
    al_init();
    al_init_primitives_addon();
	//al_init_image_addon();
	
	displaySizeX = 1000;
	displaySizeY = 1000;
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

void DrawingClass::DrawPlanets()//hardcoded planet radius
{
	//ALLEGRO_BITMAP *image = al_load_bitmap("C:/Users/Dell/3D Objects/planet.png");
	for (Planet& a : *planets)
	{
		al_draw_filled_circle(a.GetXPos() + displaySizeX / 2, displaySizeY / 2 - a.GetYPos(), 10, al_map_rgb(120, 120, 0));
		//al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), a.GetXPos() + displaySizeX / 2, displaySizeY / 2 - a.GetYPos(), 30, 30, 0);
	}
}

void DrawingClass::DrawRockets()//hardcoded rocket size
{
	for (Rocket& a : *rockets)
	{
		if(a.GetAlive())
			al_draw_filled_circle(a.GetXPos() + displaySizeX / 2, displaySizeY / 2 - a.GetYPos(), 5, al_map_rgb(120, 0, 0));
		//al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), a.GetXPos() + displaySizeX / 2, displaySizeY / 2 - a.GetYPos(), 30, 30, 0);
	}
}

void DrawingClass::CloseWindow()
{
    al_destroy_display(disp);
    disp = nullptr;
}
DrawingClass::~DrawingClass()
{
    if(disp!= nullptr) al_destroy_display(disp);
}