#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
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

	int liftH = 0;
	int liftW = 0; 
	bool floor2 = false;


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
	ALLEGRO_BITMAP *Panel1 = NULL;
	ALLEGRO_BITMAP *Panel2 = NULL;
	ALLEGRO_BITMAP *panel3 = NULL;
	ALLEGRO_BITMAP *Panel4 = NULL;

	ALLEGRO_BITMAP *LiftOpen = NULL;
	ALLEGRO_BITMAP *Liftclose = NULL;

	ALLEGRO_BITMAP *Elevator = NULL;

	ALLEGRO_SAMPLE *sample = NULL;



	
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
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);

	Elevator = al_load_bitmap("Elevator.png");
	LiftOpen = al_load_bitmap("LiftOpen.png");
	Liftclose = al_load_bitmap("LiftClose.png");
	
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
	Panel1 = al_load_bitmap("MetalPlate2.png");
	Panel2= al_load_bitmap("MetalPlate2.png");
	panel3= al_load_bitmap("MetalPlate2.png");
	Panel4= al_load_bitmap("MetalPlate2.png");

	sample = al_load_sample("Music.wav");

	liftH = al_get_bitmap_height(Liftclose);
	liftW = al_get_bitmap_width(Liftclose);

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	//al_hide_mouse_cursor(display);
	while (!done)
	{
		al_draw_line(465, 0, 465, 700, al_map_rgb(121, 121, 121), 5);
		al_draw_bitmap(Elevator, 440 - liftW / 2, 700 - liftH - 100, 0);

		al_draw_bitmap(Liftclose, 250 - liftW / 2, 700 - liftH - 100, 0);
		al_draw_bitmap(Liftclose, 250 - liftW / 2, 550 - liftH - 100, 0);
		al_draw_bitmap(Liftclose, 250 - liftW / 2, 400 - liftH - 100, 0);
		al_draw_bitmap(Liftclose, 250 - liftW / 2, 250 - liftH - 100, 0);
		al_draw_bitmap(Plate, 600, 0,0);

		al_draw_bitmap(But1,610,75,0);
		al_draw_bitmap(But2, 750, 75, 0);

		al_draw_bitmap(But3, 610, 140, 0);
		al_draw_bitmap(But4, 750, 140, 0);


		al_draw_bitmap(Open, 610, 205, 0);
		al_draw_bitmap(Close, 750, 205, 0);

		al_draw_bitmap(Alarm, 680, 270, 0);
		al_draw_line(0, 150, 600, 150, al_map_rgb(255, 0, 0), 2);
		al_draw_line(0, 300, 600, 300, al_map_rgb(255, 0, 0), 2);
		al_draw_line(0, 450, 600, 450, al_map_rgb(255, 0, 0), 2);
		al_draw_line(0, 600, 600, 600, al_map_rgb(255, 0, 0), 2);

		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
		//al_rest(10.0);

		al_draw_bitmap(Panel1,0, 450, 0);
		al_draw_bitmap(ButUp1, 10, 450, 0);
		al_draw_bitmap(ButDown1, 10, 510, 0);

		al_draw_bitmap(Panel1, 0, 300, 0);
		al_draw_bitmap(ButUp2, 10, 300, 0);
		al_draw_bitmap(ButDown2, 10, 360,0);

		al_draw_bitmap(Panel1, 0, 150, 0);
		al_draw_bitmap(ButUp3, 10, 140, 0);
		al_draw_bitmap(ButDown3, 10, 200, 0);
		
		al_draw_bitmap(Panel1, 0,0, 0);
		al_draw_bitmap(ButUp4, 10, 0,0); 
		al_draw_bitmap(ButDown4, 10, 60, 0);

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1 && pos_x > 630 && pos_x<720 && pos_y >90 && pos_y < 140)
				done = true;// but1

			else if (ev.mouse.button & 1 && pos_x>770 && pos_x<860 && pos_y>90 && pos_y<140)
				floor2 = true; //but2

			else if (ev.mouse.button & 1 && pos_x>630 && pos_x<720 && pos_y >160 && pos_y < 210)
				done = true;// but3

			else if (ev.mouse.button & 1 && pos_x>770 && pos_x<860 && pos_y>160 && pos_y<210)
				done = true;// but4

			else if (ev.mouse.button & 1 && pos_x>630 && pos_x<720 && pos_y >230 && pos_y < 280)
				done = true;// open

			else if (ev.mouse.button & 1 && pos_x>770 && pos_x<860 && pos_y>230&& pos_y<280)
				done = true;// close

			else if (ev.mouse.button & 1 && pos_x>700 && pos_x<800 && pos_y> 295 && pos_y<345)
				done = true;// Alarm

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 470 && pos_y<515)
				done = true;// up1

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 530 && pos_y<575)
				done = true;// down1

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 320 && pos_y<365)
				done = true;// up2

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 380 && pos_y<425)
				done = true;// down2

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 160 && pos_y<205)
				done = true;// up3

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 220 && pos_y<265)
				done = true;// down3

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 25 && pos_y<70)
				done = true;// up4

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x<125 && pos_y> 85 && pos_y<130)
				done = true;// down4


			else if (ev.mouse.button & 2)
				done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}

	/*		while (floor2 && liftH != 115)
			{
				liftH + 10;
				al_draw_bitmap(Liftclose, 400 - liftW / 2, 700 - liftH - 100, 0);
			}// but2
		
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

	al_destroy_sample(sample);

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}