#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "Elevator.h"

const int NumFloors = 4;

void InitElevator(Elevatorm elevatorm[], int size);
void DrawElevator(Elevatorm elevatorm[], int size);
void FireElevator(Elevatorm elevatorm[], int size);
void UpdateElevator(Elevatorm elevatorm[], int size, int floor, ALLEGRO_FONT *font);
//void UpdateFloorNum(Elevatorm elevatorm, int floor);

int main(void)
{
	Elevatorm elevatorm[5];

	int width = 900;
	int height = 700;

	int alarmS = 0;
	int floor = 0;
	const int FPS = 60;
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
	ALLEGRO_BITMAP *ButUp2 = NULL;
	ALLEGRO_BITMAP *ButUp3 = NULL;
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

	ALLEGRO_BITMAP *Black = NULL;
	ALLEGRO_BITMAP *Elevator = NULL;

	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_SAMPLE_INSTANCE *alarm = NULL;

	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT ev;

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
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf addon
	al_reserve_samples(1);

	ALLEGRO_FONT *font = al_load_ttf_font("Digital.ttf", 72, 0);

	Black = al_load_bitmap("Black.png");
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
	
	ButDown2 = al_load_bitmap("ElevatorButtonDown.png");
	ButDown3 = al_load_bitmap("ElevatorButtonDown.png");
	ButDown4 = al_load_bitmap("ElevatorButtonDown.png");

	Plate = al_load_bitmap("MetalPlate.png");
	Open = al_load_bitmap("ElevatorButtonOpen.png");
	Close = al_load_bitmap("ElevatorButtonClose.png");
	Alarm = al_load_bitmap("ElevatorButtonA.png");
	Panel1 = al_load_bitmap("MetalPlate2.png");
	Panel2 = al_load_bitmap("MetalPlate2.png");
	panel3 = al_load_bitmap("MetalPlate2.png");
	Panel4 = al_load_bitmap("MetalPlate2.png");

	sample = al_load_sample("Music.wav");
	alarm = al_create_sample_instance(al_load_sample("Alarm.wav"));

	al_attach_sample_instance_to_mixer(alarm, al_get_default_mixer());

	liftH = al_get_bitmap_height(Liftclose);
	liftW = al_get_bitmap_width(Liftclose);

	int x = 440 - liftW / 2;
	int y = 700 - liftH - 100;

	InitElevator(elevatorm, NumFloors);
	
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));


	//al_hide_mouse_cursor(display);
	al_start_timer(timer);
	while (!done)
	{
		al_draw_line(0, 150, 600, 150, al_map_rgb(255, 0, 0), 2);
		al_draw_line(0, 300, 600, 300, al_map_rgb(255, 0, 0), 2);
		al_draw_line(0, 450, 600, 450, al_map_rgb(255, 0, 0), 2);
		al_draw_line(0, 600, 600, 600, al_map_rgb(255, 0, 0), 2);
		al_draw_line(465, 0, 465, 700, al_map_rgb(121, 121, 121), 200);
		//al_draw_bitmap(Elevator, x, y, 0);

		al_draw_bitmap(Liftclose, 250 - liftW / 2, 700 - liftH - 100, 0);
		al_draw_bitmap(Liftclose, 250 - liftW / 2, 550 - liftH - 100, 0);
		al_draw_bitmap(Liftclose, 250 - liftW / 2, 400 - liftH - 100, 0);
		al_draw_bitmap(Liftclose, 250 - liftW / 2, 250 - liftH - 100, 0);
		al_draw_bitmap(Plate, 600, 0, 0);

		al_draw_bitmap(But1, 610, 75, 0);
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

		al_play_sample(sample, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
		//al_rest(10.0);

		al_draw_bitmap(Panel1, 0, 450, 0);
		al_draw_bitmap(ButUp1, 10, 450, 0);

		al_draw_bitmap(Panel1, 0, 300, 0);
		al_draw_bitmap(ButUp2, 10, 300, 0);
		al_draw_bitmap(ButDown2, 10, 360, 0);

		al_draw_bitmap(Panel1, 0, 150, 0);
		al_draw_bitmap(ButUp3, 10, 140, 0);
		al_draw_bitmap(ButDown3, 10, 200, 0);

		al_draw_bitmap(Panel1, 0, 0, 0);
		al_draw_bitmap(ButDown4, 10, 60, 0);

		//ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			draw = true;

			UpdateElevator(elevatorm, NumFloors, floor, font);
			//UpdateFloorNum(elevatorm, floor);

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{

			if (ev.mouse.button & 1 && pos_x > 630 && pos_x < 720 && pos_y >90 && pos_y < 140)
			{
				floor = 525;
				FireElevator(elevatorm, NumFloors);
				//al_draw_bitmap(LiftOpen, 250 - liftW / 2, 700 - liftH - 100, 0);
				//al_rest(5);
			}// but1

			else if (ev.mouse.button & 1 && pos_x>770 && pos_x < 860 && pos_y>90 && pos_y < 140)
			{
				floor = 375;
				FireElevator(elevatorm, NumFloors);
				/*al_draw_bitmap(LiftOpen, 250 - liftW / 2, 550 - liftH - 100, 0);
				al_draw_bitmap(Black, x, y, 0);
				al_draw_bitmap(Elevator, x, y - 150, 0);
				al_flip_display();
				al_rest(5);*/
			} //but2

			else if (ev.mouse.button & 1 && pos_x>630 && pos_x < 720 && pos_y >160 && pos_y < 210)
			{
				floor = 225;
				FireElevator(elevatorm, NumFloors);
				
				/*al_draw_bitmap(LiftOpen, 250 - liftW / 2, 400 - liftH - 100, 0);
				al_draw_bitmap(Black, x, y, 0);
				al_draw_bitmap(Elevator, x, y - 300, 1);
				al_flip_display();
				al_rest(5);*/
			} // but3

			else if (ev.mouse.button & 1 && pos_x>770 && pos_x < 860 && pos_y>160 && pos_y < 210)
			{
				floor = 75;
				FireElevator(elevatorm, NumFloors);	
				/*al_draw_bitmap(LiftOpen, 250 - liftW / 2, 250 - liftH - 100, 0);
				al_draw_bitmap(Black, x, y, 0);
				al_draw_bitmap(Elevator, x, y - 450, 1);
				al_flip_display();
				al_rest(5);*/
			} // but4

			else if (ev.mouse.button & 1 && pos_x>630 && pos_x < 720 && pos_y >230 && pos_y < 280)
			{
				al_draw_bitmap(LiftOpen, 250 - liftW / 2, floor-75, 0);
				al_flip_display();
				al_rest(2);
			}// open

			else if (ev.mouse.button & 1 && pos_x>770 && pos_x < 860 && pos_y>230 && pos_y < 280)
				;// close

			else if (ev.mouse.button & 1 && pos_x>700 && pos_x < 800 && pos_y> 295 && pos_y < 345)
			{
				alarmS += 1;
				if (alarmS%2 != 0)
				{
					al_play_sample_instance(alarm);
				}// Alarm
				else
				{
					al_stop_sample_instance(alarm);
				}

			}

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x < 125 && pos_y> 470 && pos_y < 515)
				done = true;// up1

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x < 125 && pos_y> 320 && pos_y < 365)
				done = true;// up2

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x < 125 && pos_y> 380 && pos_y < 425)
				done = true;// down2

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x < 125 && pos_y> 160 && pos_y < 205)
				done = true;// up3

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x < 125 && pos_y> 220 && pos_y < 265)
				done = true;// down3

			else if (ev.mouse.button & 1 && pos_x>20 && pos_x < 125 && pos_y> 85 && pos_y < 130)
				done = true;// down4


			else if (ev.mouse.button & 2)
				done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}
		
		if (draw && al_is_event_queue_empty(event_queue))
		{
			draw = false;
         	DrawElevator(elevatorm, NumFloors);

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
}
	al_destroy_bitmap(But1); //destroy our display object
	al_destroy_bitmap(But2);
	al_destroy_bitmap(But3);
	al_destroy_bitmap(But4);
	al_destroy_bitmap(ButUp1);
	al_destroy_bitmap(ButUp2);
	al_destroy_bitmap(ButUp3);
	al_destroy_bitmap(ButDown2);
	al_destroy_bitmap(ButDown3);
	al_destroy_bitmap(ButDown4);
	al_destroy_bitmap(Open);
	al_destroy_bitmap(Close);
	al_destroy_bitmap(Alarm);

	al_destroy_sample(sample);


	al_destroy_event_queue(event_queue);
	if (ev.type == ALLEGRO_EVENT_TIMER)
	{
		draw = true;
		al_destroy_display(display);	//destroy our display object

		return 0;
	}					
}

void InitElevator(Elevatorm elevatorm[], int size)
{
	for (int i = 0; i < size; i++)
	{
		elevatorm[i].ID = ELEVATORM;
		elevatorm[i].speed = 10;
		elevatorm[i].up = false;
	}
}

void DrawElevator(Elevatorm elevatorm[], int size)
{
	
		if (elevatorm[1].up)
		{
			al_draw_filled_circle(elevatorm[1].x, elevatorm[1].y, 60, al_map_rgb(0, 0, 0));
		}
			
}
void FireElevator(Elevatorm elevatorm[], int size)
{
	
		if (!elevatorm[1].up)
		{
			elevatorm[1].x = 458;
			elevatorm[1].y = 500;
			elevatorm[1].up = true;
		
		}

}
void UpdateElevator(Elevatorm elevatorm[], int size, int floor, ALLEGRO_FONT *font)
{
	
		if (elevatorm[1].up)
		{
			if (elevatorm[1].y<floor)
			{ 
				elevatorm[1].y += 2;
				if (elevatorm[1].y >= 0 && elevatorm[1].y < 150)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "4");
				}
				if (elevatorm[1].y >= 150 && elevatorm[1].y < 300)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "3");
				}
				if (elevatorm[1].y >= 300 && elevatorm[1].y < 450)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "2");
				}
				if (elevatorm[1].y >= 450 && elevatorm[1].y < 600)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "1");
				}
				if (elevatorm[1].y > floor)
					elevatorm[1].y = floor;
			}

			else if (elevatorm[1].y > floor)
			{
				elevatorm[1].y -= 2;
				if (elevatorm[1].y >= 0 && elevatorm[1].y < 150)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "4");
				}
				if (elevatorm[1].y >= 150 && elevatorm[1].y < 300)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "3");
				}
				if (elevatorm[1].y >= 300 && elevatorm[1].y < 450)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "2");
				}
				if (elevatorm[1].y >= 450 && elevatorm[1].y < 600)
				{
					al_draw_text(font, al_map_rgb(255, 0, 0), 750, (350), ALLEGRO_ALIGN_CENTRE, "1");
				}
				if (elevatorm[1].y < floor)
					elevatorm[1].y = floor;

			}
        }
}

/*void UpdateFloorNum(Elevatorm elevatorm[], int floor)
{
	if (floor>=0 && floor<150)
	al_clear_to_color(al_map_rgb(50, 10, 70));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Your Text Here!");

	al_flip_display();
}*/