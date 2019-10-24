#include "enemies.h"

#include "player.h"

namespace Flappy_Bird
{
	PIPES buttomPipe1;
	PIPES buttomPipe2;
	PIPES superiorPipe1;
	PIPES superiorPipe2;
	float SPEED_ENEMI = 200.0f;

	static float height = 200;
	static float width = 50;

	static bool screenCenter;

	void InitialiceEnemies()
	{
		superiorPipe1.objet.height = static_cast<float>(GetRandomValue(static_cast<int>(height / 2), static_cast<int>(height + height / 3)));
		superiorPipe1.objet.width = width;
		superiorPipe1.objet.x = static_cast<float>(GetScreenWidth());
		superiorPipe1.objet.y = 0;

		buttomPipe1.objet.height = GetScreenHeight() - (superiorPipe1.objet.height + GetScreenHeight() / 3);
		buttomPipe1.objet.width = width;
		buttomPipe1.objet.x = static_cast<float>(GetScreenWidth());
		buttomPipe1.objet.y = static_cast<float>(GetScreenHeight() - buttomPipe1.objet.height);

		//seconds traps

		superiorPipe2.objet.height = static_cast<float>(GetRandomValue(static_cast<int>(height / 2), static_cast<int>(height + height / 3)));
		superiorPipe2.objet.width = width;
		superiorPipe2.objet.x = static_cast<float>(GetScreenWidth());
		superiorPipe2.objet.y = 0;

		buttomPipe2.objet.height = GetScreenHeight() - (superiorPipe2.objet.height + GetScreenHeight() / 3);
		buttomPipe2.objet.width = width;
		buttomPipe2.objet.x = static_cast<float>(GetScreenWidth());
		buttomPipe2.objet.y = static_cast<float>(GetScreenHeight() - buttomPipe1.objet.height);

		screenCenter = false;
	}

	void MovementEnemies()
	{
		if ((buttomPipe1.objet.x + width < 0) && (superiorPipe1.objet.x + width < 0))
		{
			superiorPipe1.objet.height = static_cast<float>(GetRandomValue(static_cast<int>(height / 2), static_cast<int>(height)));
			superiorPipe1.objet.x = static_cast<float>(GetScreenWidth());
			superiorPipe1.objet.y = 0;

			buttomPipe1.objet.height = GetScreenHeight() - (superiorPipe1.objet.height + GetScreenHeight() / 3);
			buttomPipe1.objet.x = static_cast<float>(GetScreenWidth());
			buttomPipe1.objet.y = static_cast<float>(GetScreenHeight() - buttomPipe1.objet.height);

			screenCenter = false;
		}

		//seconds traps
		if ((buttomPipe1.objet.x + width/2 < GetScreenWidth() / 2) && ((superiorPipe1.objet.x + width/2 < GetScreenWidth() / 2)) &&
			(screenCenter == false))
		{
			superiorPipe2.objet.height = static_cast<float>(GetRandomValue(static_cast<int>(height / 2), static_cast<int>(height)));
			superiorPipe2.objet.x = static_cast<float>(GetScreenWidth());
			superiorPipe2.objet.y = 0;

			buttomPipe2.objet.height = GetScreenHeight() - (superiorPipe2.objet.height + GetScreenHeight() / 3);
			buttomPipe2.objet.x = static_cast<float>(GetScreenWidth());
			buttomPipe2.objet.y = static_cast<float>(GetScreenHeight() - buttomPipe2.objet.height);

			screenCenter = true;
		}

		superiorPipe1.objet.x -= SPEED_ENEMI * GetFrameTime();
		buttomPipe1.objet.x -= SPEED_ENEMI * GetFrameTime();

		superiorPipe2.objet.x -= SPEED_ENEMI * GetFrameTime();
		buttomPipe2.objet.x -= SPEED_ENEMI * GetFrameTime();
	}

	void DrawEnemies()
	{
		DrawRectangleRec(superiorPipe1.objet, RED);
		DrawRectangleRec(buttomPipe1.objet, RED);

		DrawRectangleRec(superiorPipe2.objet, RED);
		DrawRectangleRec(buttomPipe2.objet, RED);
	}
}