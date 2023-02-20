#pragma once

#include "Awesome Library/AwesomeLibrary.h"
#include "GameState.h"

class Menu
{
private:

	GameState state;


	void drawWelcome();
	void drawMenuOptions(int x, int y, Color color);

public:

	Menu();
	GameState updateMenu();
};

