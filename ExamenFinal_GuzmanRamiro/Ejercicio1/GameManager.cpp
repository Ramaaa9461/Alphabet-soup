#include "GameManager.h"

#include <iostream>

using namespace std;


GameManager* GameManager::S_GameManager = nullptr;

GameManager* GameManager::getGameManager()
{
	if (S_GameManager == nullptr) {
		S_GameManager = new GameManager();
	}
	return S_GameManager;
}

void GameManager::changeState(GameState newState)
{
	state = newState;
}

void GameManager::changeInsideGameBoolean(bool insideGame)
{
	this->insideGame = insideGame;
}

GameManager::GameManager()
{
	init();

	while (insideGame)
	{
		update();
	}

	deInit();
}

void GameManager::deInit()
{
	delete menu;
	delete game;
	delete stats;
}

void GameManager::init()
{
	srand(time(NULL));
	hideCursor();

	menu = new Menu();
	game = new Game();
	stats = new PlayersStats();

	game->initGame();
}

void GameManager::update()
{
	switch (state)
	{

	case GameState::StateMenu:

		if (!resetValues)
		{
			resetValues = true;
		}
		state = menu->updateMenu();

		break;

	case GameState::StateGame:

		if (resetValues)
		{
			game->resetGame();
			resetValues = false;
		}
		state = game->updateGame();

		break;

	case GameState::StateStats:

		stats->updatePlayerStats();

		break;

	case GameState::StateExit:

		insideGame = false;

		break;

	default:
		break;
	}

}