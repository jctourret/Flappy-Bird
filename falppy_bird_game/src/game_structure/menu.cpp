#include "menu.h"

#include "raylib.h"

#include "game_screen.h"
#include "game_objets/player.h"

namespace Flappy_Bird
{
	STATE scenes;

	static int fontTittle = 50;
	static int fontSubTittle = 20;

	void InitialiceMenu()
	{
		scenes = menu;
	}

	void InputMenu()
	{
		if (IsKeyPressed(KEY_ENTER) == true)
		{
			InitialicePlayer();
			scenes = game;
		}

		if (IsKeyPressed(KEY_ESCAPE) == true)
		{
			player.exitGame = true;
		}
	}

	void DrawMenu()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("FLAPPY BIRD", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, fontTittle, GREEN);

		DrawText("press ENTER", GetScreenWidth() / 2 - 60, GetScreenHeight() / 2 + 60, fontSubTittle, WHITE);

		EndDrawing();
	}
}