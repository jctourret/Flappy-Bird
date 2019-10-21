#include "credits.h"

#include "raylib.h"

#include "menu.h"
#include "game_objets/player.h"

namespace Flappy_Bird
{
	static int fontTittle = 50;
	static int fontSubTittle = 20;

	void InputCredits()
	{
		if (IsKeyPressed(KEY_ENTER) == true)
		{
			scenes = menu;
		}

		if (IsKeyPressed(KEY_ESCAPE) == true)
		{
			player.exitGame = true;
		}
	}

	void DrawCredits()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("Credits", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2, fontTittle, GREEN);

		DrawText(FormatText("Points ~ %i", player.points), GetScreenWidth() / 2 - 70, GetScreenHeight() / 2 + 60, fontSubTittle, DARKGREEN);

		EndDrawing();
	}
}