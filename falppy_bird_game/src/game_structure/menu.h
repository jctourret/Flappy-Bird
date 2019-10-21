#ifndef MENU_H
#define MENU_H

namespace Flappy_Bird
{
	enum STATE {
		game, exit, menu, credits
	};

	extern STATE scenes;

	void InitialiceMenu();
	void InputMenu();
	void DrawMenu();
}

#endif // !MENU_H

