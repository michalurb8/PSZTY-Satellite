#include "DrawingClass.h"

DrawingClass::DrawingClass()
{
    disp = nullptr;
    al_init();
    al_init_primitives_addon();
}

DrawingClass::~DrawingClass()
{
    if(disp!= nullptr) al_destroy_display(disp);
}

void DrawingClass::LoadPlanets(std::vector<Planet> *Arg, int homeId, int targetId)
{
    planets = Arg;
	homePlanetId = homeId;
	targetPlanetId = targetId;
}

void DrawingClass::LoadRockets(std::vector<Rocket>* Arg)
{
	rockets = Arg;
}

void DrawingClass::DisplayFrame()
{
    if(!disp) disp = al_create_display(screenX, screenY);
	al_clear_to_color(al_map_rgb(15,0,40));
	DrawPlanets();
	DrawRockets();
    al_flip_display();
}

void DrawingClass::DrawPlanets()
{
	for (Planet& p : *planets)
	{
		al_draw_filled_circle(p.GetXPos() + screenX/2, screenY/2 - p.GetYPos(), planetSize, al_map_rgb(100, 50, 0));
	}
	Planet& target = (*planets)[targetPlanetId];
	al_draw_circle(target.GetXPos() + screenX/2, screenY/2 - target.GetYPos(), planetSize, al_map_rgb(200, 100, 0), 0.3 * planetSize);
	Planet& home = (*planets)[homePlanetId];
	al_draw_circle(home.GetXPos() + screenX/2, screenY/2 - home.GetYPos(), planetSize, al_map_rgb(100, 50, 150), 0.3 * planetSize);

}

void DrawingClass::DrawRockets()
{
	for (Rocket& r : *rockets)
	{
		if(r.GetAlive())
			al_draw_filled_circle(r.GetXPos() + screenX/2, screenY/2 - r.GetYPos(), rocketSize, al_map_rgb(0, 100, 0));
	}
}

void DrawingClass::CloseWindow()
{
    al_destroy_display(disp);
    disp = nullptr;
}