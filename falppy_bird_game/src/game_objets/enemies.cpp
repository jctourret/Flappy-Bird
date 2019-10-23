#include "enemies.h"

#include <iostream>

namespace Flappy_Bird
{
	PIPES buttomPipe;
	PIPES superiorPipe;
	float SPEED_ENEMI = 200.0f;

	static float height = 200;
	static float width = 50;

	void InitialiceEnemies()
	{
		superiorPipe.objet.x = static_cast<float>(GetScreenWidth());
		superiorPipe.objet.y = 0;
		superiorPipe.objet.height = height;
		superiorPipe.objet.width = width;

		buttomPipe.objet.x = static_cast<float>(GetScreenWidth());
		buttomPipe.objet.y = static_cast<float>(GetScreenHeight() - height);
		buttomPipe.objet.height = height;
		buttomPipe.objet.width = width;
	}

	void MovementEnemies()
	{
		if ((buttomPipe.objet.x + width < 0) && (superiorPipe.objet.x + width < 0))
		{
			superiorPipe.objet.height = static_cast<float>(GetRandomValue(static_cast<int>(height / 2), static_cast<int>(height)));
			superiorPipe.objet.y = 0;

			superiorPipe.objet.x = static_cast<float>(GetScreenWidth());


			//buttomPipe.objet.height = static_cast<float>(GetRandomValue(static_cast<int>(height / 2), static_cast<int>(height)));
			buttomPipe.objet.height = GetScreenHeight() - (superiorPipe.objet.height + GetScreenHeight() / 3);
			buttomPipe.objet.y = static_cast<float>(GetScreenHeight() - buttomPipe.objet.height);

			buttomPipe.objet.x = static_cast<float>(GetScreenWidth());
		}

		superiorPipe.objet.x -= SPEED_ENEMI * GetFrameTime();
		buttomPipe.objet.x -= SPEED_ENEMI * GetFrameTime();
	}

	void DrawEnemies()
	{
		DrawRectangleRec(superiorPipe.objet, RED);

		DrawRectangleRec(buttomPipe.objet, RED);
	}
}