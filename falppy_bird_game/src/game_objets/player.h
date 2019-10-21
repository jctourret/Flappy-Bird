#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

namespace Flappy_Bird
{
	enum WIN_OR_LOSE {
		win, lose, inGame
	};

	struct PLAYER {
		Vector2 position;
		float radius;
		int points;
		bool exitGame;
		WIN_OR_LOSE winOrLose;
	};

	extern PLAYER player;

	extern short fontUI;
	extern short pixelsAxis;

	void InitialicePlayer();
	void Input();
	void LoseOrWin();
	void DrawUI();

}

#endif // ENEMIES_H

