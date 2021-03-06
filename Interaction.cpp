#include "Interaction.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Globals.h"
#include <iostream>

int Interaction::FPS = 50;

int Interaction::initialized = 0;

Interaction::Interaction()
{
    if (!initialized)
        Initialize();
    initialized++;
}

Interaction::~Interaction()
{
    initialized--;
}

void Interaction::Initialize()
{
    if (!al_init())
    {
        std::cerr << "Allegro not initialized correctly " << strerror(errno) << std::endl;
    }
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_image_addon();
    al_install_mouse();
    al_install_keyboard();
}
