#include "enemies.h"

namespace Flappy_Bird
{
	PIPES pipes;
	float SPEED_ENEMI = 200.0f;

	static float height = 300;
	static float width = 50;

	void InitialiceEnemies()
	{
		pipes.objet.x = static_cast<float>(GetScreenWidth());
		pipes.objet.y = static_cast<float>(GetScreenHeight() - height);
		pipes.objet.height = height;
		pipes.objet.width = width;
	}

	void MovementEnemi()
	{
		if (pipes.objet.x + width < 0)
		{
			pipes.objet.x = static_cast<float>(GetScreenWidth());
		}
		pipes.objet.x -= SPEED_ENEMI * GetFrameTime();
		
	}

}