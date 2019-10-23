#include "player.h"

#include "enemies.h"
#include "game_structure/menu.h"
#include "game_structure/game_screen.h"

namespace Flappy_Bird
{
	PLAYER player;

	bool pause;

	short fontUI = 20;
	short pixelsAxis = 20;

	static float SPEEDPJ = 300.0f;
	static float SPEEDFALL = 150.0f;

	static short heightRec = 10;
	static short widthRec = 70;

	void InitialicePlayer()
	{
		player.winOrLose = inGame;

		player.position = { static_cast <float>(GetScreenWidth() / 3), static_cast <float>(GetScreenHeight() / 2) };
		player.radius = 15;
		player.points = 0;
		player.exitGame = false;

		pause = false;
	}

	void Input()
	{
		if (IsKeyPressed(KEY_ESCAPE) == true)
		{
			scenes = menu;
		}

		if (IsKeyPressed(KEY_ENTER) == true)
		{
			pause = !pause;
		}

		if (pause == false)
		{
			if (IsKeyPressed(KEY_SPACE) == true)
			{
				player.position.y -= SPEEDPJ * 10 * GetFrameTime();
			}
			else
			{
				player.position.y += SPEEDFALL * GetFrameTime();
			}
		}
	}

	void LoseOrWin()
	{
		if (CheckCollisionCircleRec(player.position, player.radius, pipes.objet) == true)
		{
			scenes = credits;
		}

		if ((player.position.y + player.radius >= GetScreenHeight()) ||
			(player.position.y - player.radius <= 0))
		{
			scenes = credits;
		}
	}

	void EarnPoint()
	{
		if (player.position.x > (pipes.objet.x + pipes.objet.width - 5) && player.position.x < (pipes.objet.x + pipes.objet.width))
		{
			player.points++;
		}
	}

	void DrawUI()
	{
		DrawText(FormatText("Points ~ %i", player.points), pixelsAxis, screenHeight - pixelsAxis, fontUI, WHITE);
	}
}