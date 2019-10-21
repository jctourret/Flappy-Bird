#include "player.h"

#include "game_structure/game_screen.h"
#include "game_structure/menu.h"

namespace Flappy_Bird
{
	PLAYER player;

	short fontUI = 20;
	short pixelsAxis = 20;

	static float SPEEDPJ = 300.0f;
	static float SPEEDFALL = 150.0f;

	static short heightRec = 10;
	static short widthRec = 70;

	void InitialicePlayer()
	{
		player.winOrLose = inGame;

		player.position = { static_cast <float>(GetScreenWidth() / 3), static_cast <float>(GetScreenHeight()/2) };
		player.radius = 15;
		player.points = 0;
		player.exitGame = false;
	}

	void Input()
	{
		if (IsKeyPressed(KEY_SPACE) == true)
		{
			player.position.y -= SPEEDPJ * 10 * GetFrameTime();
		}
		else
		{
			player.position.y += SPEEDFALL * GetFrameTime();
		}
		
		if (IsKeyPressed(KEY_ESCAPE) == true)
		{
			player.exitGame = true;
		}
	}

	void LoseOrWin()
	{
		if ((player.position.y + player.radius >= GetScreenHeight()) || 
			(player.position.y - player.radius <= 0))
		{
			scenes = credits;
		}
	}

	void DrawUI()
	{
		DrawText(FormatText("~POINTS~ %i", player.points), screenWidth / 2 + screenWidth / 3, screenHeight - pixelsAxis, fontUI, WHITE);
	}
}