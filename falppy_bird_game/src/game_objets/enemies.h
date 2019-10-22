#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Flappy_Bird
{
	struct PIPES {
		Rectangle objet;
	};

	extern PIPES pipes;
	extern float SPEED_ENEMI;

	void InitialiceEnemies();
	void MovementEnemi();

}

#endif // !ENEMIES_H
