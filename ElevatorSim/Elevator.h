//Object IDs
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <vector>
using namespace std;
enum IDS{ ELEVATORM };

class Elevatorm
{
private:

	int ID;
	int x;
	int y;
	bool up;
	int speed;

public:
	void InitElevator(Elevatorm elevatorm[], int size);
	void DrawElevator(Elevatorm elevatorm[], int size);
	void FireElevator(Elevatorm elevatorm[], int size);
	void UpdateElevator(Elevatorm elevatorm[], int size, int floor, int clickCheck, vector<int> floorQ, ALLEGRO_FONT *font, bool moveDone);
	void DrawNumber(Elevatorm elevatorm[], int size, ALLEGRO_FONT *font);
};