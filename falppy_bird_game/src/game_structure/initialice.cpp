#include "initialice.h"

#include "game_objets/player.h"
#include "game_screen.h"
#include "game_structure/menu.h"

namespace Flappy_Bird
{

	void InitialiceAll()
	{
		InitWindow(screenWidth, screenHeight, "Flappy Bird - Tomas Aquistapace");
		HideCursor();

		SetExitKey(KEY_BACK);

		InitialicePlayer();
		InitialiceMenu();


		SetTargetFPS(60);
	
	}
}