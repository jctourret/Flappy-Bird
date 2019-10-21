#include "raylib.h"
#include "game_structure/game_structure.h"

using namespace Tomas_Aquistapace__Flappy_Bird;

int main()
{
	InitWindow(screenWidth, screenHeight, "Arkanoid - Tomas Aquistapace");
	HideCursor();

	SetExitKey(KEY_BACK);

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		switch (scenes)
		{
		case menu:
			break;
		case game:
			break;
		case credits:
			break;
		case winOrLose:
			break;
		}
	}

	return 0;
}