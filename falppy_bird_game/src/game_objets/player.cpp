#include "player.h"

#include "enemies.h"
#include "game_structure/menu_screen.h"
#include "game_structure/game_screen.h"
#include "game_structure/initialice.h"

namespace Flappy_Bird{
	using namespace Enemies;
	namespace Player_Things{
		PLAYER player;
		PLAYER player2;
		bool pause;

		short fontUI = 20;
		short pixelsAxis = 20;

		static float SPEEDPJ = 300.0f;
		static float SPEEDFALL = 150.0f;

		static short heightRec = 10;
		static short widthRec = 70;

		void InitialicePlayer(){
			player.winOrLose = inGame;
			player.position = { static_cast <float>(GetScreenWidth() / 3), static_cast <float>(GetScreenHeight() / 2) };
			player.radius = 15;
			player.points = 0;
			player.exitGame = false;
			pause = false;
		}
		void InitialicePlayers(){
			player.winOrLose = inGame;
			player.position = { static_cast <float>(GetScreenWidth() / 3), static_cast <float>(GetScreenHeight() / 2) };
			player.radius = 15;
			player.points = 0;
			player.exitGame = false;
			player2.winOrLose = inGame;
			player2.position = { static_cast <float>(GetScreenWidth() / 3), static_cast <float>(GetScreenHeight() / 2) };
			player2.radius = 15;
			player2.points = 0;
			player2.exitGame = false;
			pause = false;
		}
		void Input(){
			if (IsKeyPressed(KEY_ESCAPE) == true){
				ResetValues();
				scenes = menu;
			}
			if (IsKeyPressed(KEY_ENTER) == true){
				pause = !pause;
			}
			if (pause == false){
				if (IsKeyPressed(KEY_SPACE) == true){
					player.position.y -= SPEEDPJ * 10 * GetFrameTime();
				}
				else{
					player.position.y += SPEEDFALL * GetFrameTime();
				}
			}
		}
		void InputFor2(){
			if (IsKeyPressed(KEY_ESCAPE) == true) {
				ResetValues();
				scenes = menu;
			}
			if (IsKeyPressed(KEY_ENTER) == true) {
				pause = !pause;
			}
			if (pause == false) {
				if (IsKeyPressed(KEY_SPACE) == true) {
					player.position.y -= SPEEDPJ * 10 * GetFrameTime();
				}
				else {
					player.position.y += SPEEDFALL * GetFrameTime();
				}
				if (IsKeyPressed(KEY_KP_ENTER) == true) {
					player2.position.y -= SPEEDPJ * 10 * GetFrameTime();
				}
				else {
					player2.position.y += SPEEDFALL * GetFrameTime();
				}
			}
		}
		void LoseOrWin(){
			if (CheckCollisionCircleRec(player.position, player.radius, superiorPipe1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, superiorPipe2.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, buttomPipe1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, buttomPipe2.objet) == true) {
				scenes = endGame;
			}
			if ((player.position.y + player.radius >= GetScreenHeight()) ||
				(player.position.y - player.radius <= 0)) {
				scenes = endGame;
			}
		}
		void LoseOrWinFor2(){
			if (CheckCollisionCircleRec(player.position, player.radius, superiorPipe1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, superiorPipe2.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, buttomPipe1.objet) == true ||
				CheckCollisionCircleRec(player.position, player.radius, buttomPipe2.objet) == true){
				scenes = endGame;
			}
			if ((player.position.y + player.radius >= GetScreenHeight()) ||
				(player.position.y - player.radius <= 0)){
				scenes = endGame;
			}
			if (CheckCollisionCircleRec(player2.position, player2.radius, superiorPipe1.objet) == true ||
				CheckCollisionCircleRec(player2.position, player2.radius, superiorPipe2.objet) == true ||
				CheckCollisionCircleRec(player2.position, player2.radius, buttomPipe1.objet) == true ||
				CheckCollisionCircleRec(player2.position, player2.radius, buttomPipe2.objet) == true) {
				scenes = endGame;
			}
			if ((player2.position.y + player2.radius >= GetScreenHeight()) ||
				(player2.position.y - player2.radius <= 0)) {
				scenes = endGame;
			}
		}
		void EarnPoint(){
			if (player.position.x > (buttomPipe1.objet.x + buttomPipe1.objet.width - 3.5f) &&
				player.position.x <= (buttomPipe1.objet.x + buttomPipe1.objet.width)
				||
				player.position.x > (buttomPipe2.objet.x + buttomPipe2.objet.width - 3.5f) &&
				player.position.x <= (buttomPipe2.objet.x + buttomPipe2.objet.width)){
				player.points++;
			}
			if (player2.position.x > (buttomPipe1.objet.x + buttomPipe1.objet.width - 3.5f) &&
				player2.position.x <= (buttomPipe1.objet.x + buttomPipe1.objet.width)
				||
				player2.position.x > (buttomPipe2.objet.x + buttomPipe2.objet.width - 3.5f) &&
				player2.position.x <= (buttomPipe2.objet.x + buttomPipe2.objet.width)) {
				player2.points++;
			}
		}
		void DrawPlayer(){
			DrawCircle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), player.radius, GREEN);
			DrawUI();
		}
		void DrawPlayerFor2(){
			DrawCircle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), player.radius, GREEN);
			DrawCircle(static_cast<int>(player.position.x), static_cast<int>(player2.position.y), player2.radius, RED);
		}
		void DrawUI(){
			DrawText(FormatText("Points ~ %i", player.points), pixelsAxis, screenHeight - pixelsAxis, fontUI, WHITE);
		}
	}
}