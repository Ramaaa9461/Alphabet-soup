#pragma once

#include "GameState.h"

#include "Menu.h"
#include "Game.h"
#include "PlayersStats.h"

class GameManager
{

private:

	void init();
	void update();

	Menu* menu;
	Game* game;
	PlayersStats* stats;

	bool insideGame = true;
	bool resetValues = false;
	bool checkGameStats = true;

	GameState state = GameState::StateMenu;
	statisticsOfTheGame gameStats;

	void deInit();


public:

	GameManager();

};

