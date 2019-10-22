#include "flow_of_game.h"

#include "raylib.h"

#include "menu.h"
#include "credits.h"
#include "initialice.h"
#include "game_screen.h"
#include "game_objets/player.h"
#include "game_objets/enemies.h"

namespace Flappy_Bird
{
	void FlowOfGame() 
	{
		InitialiceAll();

		while (!WindowShouldClose() && player.exitGame != true)
		{
			switch (scenes)
			{
			case menu:
				InputMenu();
				DrawMenu();

				break;
			case game:

				// tiene que tener una pausa

				Input();

				MovementEnemi();

				LoseOrWin();

				DrawGame();

				break;
			case credits:

				InputCredits();
				ResetValues();
				DrawCredits();
				
				break;
			case exit:
				player.exitGame = true;

				break;
			}
		}



	}


}