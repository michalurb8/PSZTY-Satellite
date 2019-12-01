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

void DrawingClass::LoadPlanets(std::vector<Planet> *Arg, int id)
{
    planets = Arg;
	targetPlanetId = id;
}

void DrawingClass::LoadRockets(std::vector<Rocket>* Arg)
{
	rockets = Arg;
}

void DrawingClass::Draw()
{
    if(!disp) disp = al_create_display(displaySizeX, displaySizeY);
    
	al_clear_to_color(al_map_rgb(15,0,40));
	DrawPlanets();
	DrawRockets();
    al_flip_display();
}

void DrawingClass::DrawPlanets()//hardcoded planet radius
{
	//ALLEGRO_BITMAP *image = al_load_bitmap("C:/Users/Dell/3D Objects/planet.png");
	for (Planet& p : *planets)
	{
		al_draw_filled_circle(p.GetXPos() + displaySizeX / 2, displaySizeY / 2 - p.GetYPos(), 10, al_map_rgb(100, 50, 0));
		//al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), a.GetXPos() + displaySizeX / 2, displaySizeY / 2 - a.GetYPos(), 30, 30, 0);
	}
	Planet& p = (*planets)[targetPlanetId];
	al_draw_circle(p.GetXPos() + displaySizeX / 2, displaySizeY / 2 - p.GetYPos(), 10, al_map_rgb(200, 100, 0), 3.0);

}

void DrawingClass::DrawRockets()//hardcoded rocket size
{
	for (Rocket& r : *rockets)
	{
		if(r.GetAlive())
			al_draw_filled_circle(r.GetXPos() + displaySizeX / 2, displaySizeY / 2 - r.GetYPos(), 5, al_map_rgb(0, 100, 0));
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