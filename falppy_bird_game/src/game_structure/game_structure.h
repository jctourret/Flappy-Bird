#ifndef GAME_STRUCTURE_H
#define GAME_STRUCTURE_H

namespace Tomas_Aquistapace__Flappy_Bird
{
	extern int screenWidth;
	extern int screenHeight;

	enum SCENES
	{
		menu, game, credits, winOrLose
	};

	extern SCENES scenes;

}
#endif //GAME_STRUCTURE_H