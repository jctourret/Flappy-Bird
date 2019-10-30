#include "menu_screen.h"

#include "raylib.h"

#include "game_screen.h"
#include "game_objets/player.h"
#include "assets_code/textures.h"

namespace Flappy_Bird{
	STATE scenes;

	static int fontTittle = 50;
	static int fontSubTittle = 20;

	bool versusOn;

	void InitialiceMenu(){
		scenes = menu;
	}
	void InputMenu(){
		if (IsKeyPressed(KEY_SPACE) == true){
			Player_Things::InitialicePlayer();
			versusOn = false;
			scenes = game;
		}
		if (IsKeyPressed(KEY_UP) == true) {
			Player_Things::InitialicePlayers();
			versusOn = true;
			scenes = game;
		}
		if (IsKeyPressed(KEY_LEFT) == true){
			scenes = options;
		}
		if (IsKeyPressed(KEY_RIGHT) == true){
			scenes = credits;
		}
		if (IsKeyPressed(KEY_ESCAPE) == true){
			scenes = exit;
		}
	}
	void DrawMenu(){
		BeginDrawing();
		ClearBackground(BLACK);
		Textures::DrawBackground();
		DrawText("FLAPPY FLAME", GetScreenWidth() / 2 - (MeasureText("FLAPPY FLAME", fontTittle)/2), GetScreenHeight() / 5, fontTittle, GREEN);
		DrawText("press SPACE for Solo", GetScreenWidth() / 2 - (MeasureText("press SPACE for Solo",fontSubTittle)/2), (GetScreenHeight()/2) + (fontSubTittle*2), fontSubTittle, WHITE);
		DrawText("press UP for Versus", GetScreenWidth() / 2 - (MeasureText("press UP for Versus", fontSubTittle)/2), GetScreenHeight() / 2 + (fontSubTittle * 3), fontSubTittle, WHITE);
		DrawText("press LEFT for Options", GetScreenWidth() / 2 - (MeasureText("press LEFT for Options", fontSubTittle)/2), GetScreenHeight() / 2 + (fontSubTittle * 4), fontSubTittle, WHITE);
		DrawText("press RIGHT for Credits", GetScreenWidth() / 2 - (MeasureText("press RIGHT for Creditsa", fontSubTittle)/2), GetScreenHeight() / 2 + (fontSubTittle * 5), fontSubTittle, WHITE);
		EndDrawing();
	}
}