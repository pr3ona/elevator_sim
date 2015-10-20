#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h> 
#include <allegro5\allegro_acodec.h> 
#include <stdio.h>

using namespace std;
///
int screenH = 800;
int screenW = 600;

int main()
{
	/*INITIALIZE ALLEGRO 5*/
	al_init();
	if (!al_init()) 
	{
		al_show_native_message_box(0, "ERROR", "Failed to initialize Allegro 5!", "Press OK to terminate.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	/*CREATE DISPLAY*/
	ALLEGRO_DISPLAY *display;
	display = al_create_display(screenW, screenW);
	al_set_window_position(display, 200, 200);
	if (!display) 
	{
		al_show_native_message_box(0, "ERROR", "Failed to initialize the display!", "Press OK to terminate.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	return 0;
}