#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Flappy_Bird{
	namespace Player_Things{
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
		extern PLAYER player2;
		extern bool pause;

		extern short fontUI;
		extern short pixelsAxis;

		void InitialicePlayer();
		void InitialicePlayers();
		void Input();
		void InputFor2();
		void LoseOrWin();
		void LoseOrWinFor2();
		void EarnPoint();
		void DrawPlayer();
		void DrawPlayers();
		void DrawUI();
	}
}

#endif // PLAYER_H

