#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "DrawingClass.h"

DrawingClass::DrawingClass()
{
    disp = nullptr;
    al_init();
    al_init_primitives_addon();
}

void DrawingClass::LoadPlanets(std::vector<Planet> *Arg)
{
    planets = Arg;
}

void DrawingClass::Draw()
{
    if(!disp) disp = al_create_display(1000, 1000);

    sleep(1);

    al_draw_circle(500,500, 19, al_map_rgb(120, 120,0), 5);
    al_flip_display();

    sleep(1);
}

void DrawingClass::CloseWindow()
{
    al_destroy_display(disp);
    disp = nullptr;
}