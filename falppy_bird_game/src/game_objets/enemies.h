#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Flappy_Bird
{
	struct PIPES {
		Rectangle objet;
	};

	extern PIPES buttomPipe;
	extern PIPES superiorPipe;
	extern float SPEED_ENEMI;

	void InitialiceEnemies();
	void MovementEnemies();
	void DrawEnemies();
}

#endif // !ENEMIES_H
