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
	GameState state = GameState::StateMenu;

	static GameManager* S_GameManager;
	GameManager();
	void deInit();


public:

	static GameManager* getGameManager();

	void changeState(GameState newState);
	void changeInsideGameBoolean(bool insideGame);

};

