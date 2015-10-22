#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

int main(void)
{
	int width = 900;
	int height = 700;

	bool done = false;
	bool draw = true;
	int pos_x = width / 2;
	int pos_y = height / 2;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *But1 = NULL;
	ALLEGRO_BITMAP *But2 = NULL;
	ALLEGRO_BITMAP *But3 = NULL;
	ALLEGRO_BITMAP *But4 = NULL;
	ALLEGRO_BITMAP *ButUp1 = NULL;
	ALLEGRO_BITMAP *ButUp2= NULL;
	ALLEGRO_BITMAP *ButUp3 = NULL;
	ALLEGRO_BITMAP *ButUp4 = NULL;
	ALLEGRO_BITMAP *ButDown1 = NULL;
	ALLEGRO_BITMAP *ButDown2 = NULL;
	ALLEGRO_BITMAP *ButDown3 = NULL;
	ALLEGRO_BITMAP *ButDown4 = NULL;

	ALLEGRO_BITMAP *Plate = NULL;
	ALLEGRO_BITMAP *Open = NULL;
	ALLEGRO_BITMAP *Close = NULL;
	ALLEGRO_BITMAP *Alarm = NULL;





	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if (!display)										//test display object
		return -1;

	if (!al_init_image_addon())							//initializing image addon
	{
		return -1;
	}


	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();

	But1 = al_load_bitmap("ElevatorButton1.png");
	But2 = al_load_bitmap("ElevatorButton2.png");
	But3 = al_load_bitmap("ElevatorButton3.png");
	But4 = al_load_bitmap("ElevatorButton4.png");

	ButUp1 = al_load_bitmap("ElevatorButtonUp.png");
	ButUp2 = al_load_bitmap("ElevatorButtonUp.png");
	ButUp3 = al_load_bitmap("ElevatorButtonUp.png");
	ButUp4 = al_load_bitmap("ElevatorButtonUp.png");

	ButDown1 = al_load_bitmap("ElevatorButtonDown.png");
	ButDown2 = al_load_bitmap("ElevatorButtonDown.png");
	ButDown3 = al_load_bitmap("ElevatorButtonDown.png");
	ButDown4 = al_load_bitmap("ElevatorButtonDown.png");

	Plate = al_load_bitmap("MetalPlate.png");
	Open = al_load_bitmap("ElevatorButtonOpen.png");
	Close = al_load_bitmap("ElevatorButtonClose.png");
	Alarm = al_load_bitmap("ElevatorButtonA.png");


	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	//al_hide_mouse_cursor(display);
	while (!done)
	{
		al_draw_bitmap(Plate, 600, 0,0);

		al_draw_bitmap(But1,610,75,0);
		al_draw_bitmap(But2, 750, 75, 0);

		al_draw_bitmap(But3, 610, 140, 0);
		al_draw_bitmap(But4, 750, 140, 0);


		al_draw_bitmap(Open, 610, 205, 0);
		al_draw_bitmap(Close, 750, 205, 0);

		al_draw_bitmap(Alarm, 680, 270, 0);
		al_draw_line(0, 150, 600, 150, al_map_rgb(255, 0, 0), 7);
		al_draw_line(0, 300, 600, 300, al_map_rgb(255, 0, 0), 7);
		al_draw_line(0, 450, 600, 450, al_map_rgb(255, 0, 0), 7);
		al_draw_line(0, 600, 600, 600, al_map_rgb(255, 0, 0), 7);


		/*al_draw_bitmap(But1, 10, 10, 0);
		al_draw_bitmap(But1, 10, 10, 0);
		al_draw_bitmap(But1, 10, 10, 0);
		al_draw_bitmap(But1, 10, 10, 0);
		al_draw_bitmap(But1, 10, 10, 0);
		al_draw_bitmap(But1, 10, 10, 0);*/

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1 && pos_x>630 && pos_x<685 && pos_y >90 && pos_y < 140)
				done = true;
			else if (ev.mouse.button & 2)
				done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}

		/*if (draw && pos_x<200)
			al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 0, 255));*/
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	al_destroy_bitmap(But1);
	al_destroy_bitmap(But2);
	al_destroy_bitmap(But3);
	al_destroy_bitmap(But4);
	al_destroy_bitmap(ButUp1);
	al_destroy_bitmap(ButUp2);
	al_destroy_bitmap(ButUp3);
	al_destroy_bitmap(ButUp4);
	al_destroy_bitmap(ButDown1);
	al_destroy_bitmap(ButDown2);
	al_destroy_bitmap(ButDown3);
	al_destroy_bitmap(ButDown4);
	al_destroy_bitmap(Open);
	al_destroy_bitmap(Close);
	al_destroy_bitmap(Alarm);

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}