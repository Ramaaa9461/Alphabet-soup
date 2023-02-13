#pragma once

#include "GameState.h"

class GameManager
{

private:

	void init();
	void update();

	void inMenu();
	void inGame();
	void inStats();



	bool insideGame = true;
	GameState state = GameState::Menu;


public:

	GameManager();

};

